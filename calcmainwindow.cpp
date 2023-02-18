//
// Created by user on 2023/2/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CalcMainWindow.h" resolved

#include "calcmainwindow.hpp"
#include "ui_CalcMainWindow.h"


CalcMainWindow::CalcMainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::CalcMainWindow) {
    ui->setupUi(this);
}

CalcMainWindow::~CalcMainWindow() {
    delete ui;
}
