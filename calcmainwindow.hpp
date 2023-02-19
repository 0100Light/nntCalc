//
// Created by user on 2023/2/17.
//

#ifndef NNTCALC_CALCMAINWINDOW_HPP
#define NNTCALC_CALCMAINWINDOW_HPP

#include <QMainWindow>
#include "cohendwidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class CalcMainWindow; }
QT_END_NAMESPACE

class CalcMainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit CalcMainWindow(QWidget *parent = nullptr);

    ~CalcMainWindow() override;

private:
    Ui::CalcMainWindow *ui;
    CohendWidget* cohendWidget;
};


#endif //NNTCALC_CALCMAINWINDOW_HPP
