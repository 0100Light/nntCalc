//
// Created by user on 2023/2/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CohendWidget.h" resolved

#include "cohendwidget.hpp"
#include "ui_CohendWidget.h"


CohendWidget::CohendWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::CohendWidget) {
    ui->setupUi(this);
}

CohendWidget::~CohendWidget() {
    delete ui;
}
