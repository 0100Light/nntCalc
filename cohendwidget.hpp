//
// Created by user on 2023/2/17.
//

#ifndef NNTCALC_COHENDWIDGET_HPP
#define NNTCALC_COHENDWIDGET_HPP

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <memory>
#include "CalculateService.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class CohendWidget; }
QT_END_NAMESPACE

class CohendWidget : public QWidget {
Q_OBJECT
    Q_PROPERTY(QString selectedMethod READ getSelectedMethod WRITE setSelectedMethod NOTIFY methodChanged)
    Q_PROPERTY(double resultNnt READ getResultNnt WRITE setResultNnt NOTIFY nntChanged)

public:
    /* ctor dtor */
    explicit CohendWidget(QWidget *parent = nullptr);
    ~CohendWidget() override;

    /* get set */
    const QString &getSelectedMethod() const;
    void setSelectedMethod(const QString &selectedMethod);
    double getResultNnt() const;
    void setResultNnt(double resultNnt);

private:
    Ui::CohendWidget *ui;
    std::unique_ptr<CalculateService> calculateService;

    /* props */
    QString selectedMethod;
    double resultNnt;
    void calc();
    void displayError();

signals:
    void methodChanged(QString);
    void nntChanged(double);
    void showMessage(QString);
};


#endif //NNTCALC_COHENDWIDGET_HPP
