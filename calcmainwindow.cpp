//
// Created by user on 2023/2/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CalcMainWindow.h" resolved

#include "calcmainwindow.hpp"
#include "ui_CalcMainWindow.h"
#include "cohendwidget.hpp"
#include <QObject>

CalcMainWindow::CalcMainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::CalcMainWindow),
        cohendWidget(new CohendWidget(this))
{
    ui->setupUi(this);

    setCentralWidget(cohendWidget);
    statusBar()->showMessage("Ready");

    connect(cohendWidget, &CohendWidget::showMessage, [=](const QString& msg){
        statusBar()->showMessage(msg);
    });
}

CalcMainWindow::~CalcMainWindow() {
    delete ui;
}
