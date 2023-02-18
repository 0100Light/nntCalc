//
// Created by user on 2023/2/17.
//

#ifndef NNTCALC_COHENDWIDGET_HPP
#define NNTCALC_COHENDWIDGET_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class CohendWidget; }
QT_END_NAMESPACE

class CohendWidget : public QWidget {
Q_OBJECT

public:
    explicit CohendWidget(QWidget *parent = nullptr);

    ~CohendWidget() override;

private:
    Ui::CohendWidget *ui;
};


#endif //NNTCALC_COHENDWIDGET_HPP
