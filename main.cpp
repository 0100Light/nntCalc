#include <QApplication>
#include <QPushButton>
#include "calcmainwindow.hpp"
#include <memory>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto mainWindow = new CalcMainWindow();
    mainWindow->show();

    return QApplication::exec();
}
