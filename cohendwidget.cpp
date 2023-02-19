//
// Created by user on 2023/2/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CohendWidget.h" resolved

#include "cohendwidget.hpp"
#include "ui_CohendWidget.h"
#include "CalculateService.hpp"


CohendWidget::CohendWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::CohendWidget),
        calculateService(std::make_unique<CalculateService>())
{
    ui->setupUi(this);

    /* connections */
    connect(this, &CohendWidget::methodChanged, ui->label_method, &QLabel::setText);
    connect(this, &CohendWidget::nntChanged, [=](double nnt){
        ui->label_nnt->setText(QString::number(nnt));
    });
    connect(ui->btnCalc, &QPushButton::clicked, [=](){
        qDebug() << "calculation button clicked";
        calc();
    });
}

CohendWidget::~CohendWidget() {
    delete ui;
}

const QString &CohendWidget::getSelectedMethod() const {
    return selectedMethod;
}

void CohendWidget::setSelectedMethod(const QString &selectedMethod) {
    CohendWidget::selectedMethod = selectedMethod;
    methodChanged(selectedMethod);
}

double CohendWidget::getResultNnt() const {
    return resultNnt;
}

void CohendWidget::setResultNnt(double resultNnt) {
    CohendWidget::resultNnt = resultNnt;
    nntChanged(resultNnt);
}

void CohendWidget::calc() {
    const auto& inputCohend = ui->lineEdit_cohend->text();
    const auto& inputCer = ui->lineEdit_cer->text();

    if (inputCohend.size() > 0){

        bool cohendOk;
        double d = inputCohend.toDouble(&cohendOk);
        bool cerOk;
        double cer = inputCer.toDouble(&cerOk);

        if (!cohendOk){
            qDebug() << "cohend error";
            displayError();
            return;
        }

        if (inputCer.size() == 0 || !cerOk){
            // use K method
            double nnt = calculateService.get()->KraemerMethod(d);
            setSelectedMethod("K");
            setResultNnt(nnt);
            return;
        }

        if (inputCer.size() > 0 && cerOk){
            if (cer < 0 || cer > 1){
                qDebug() << "'CER' range must be between 0 and 1.";
                displayError();
                return;
            }

            // use F method
            double nnt = calculateService.get()->FurukawaMethod(d, cer);
            setSelectedMethod("F");
            setResultNnt(nnt);
            return;
        }
    }

    displayError();

}

void CohendWidget::displayError() {

    setSelectedMethod("NA");
    setResultNnt(0);
}
