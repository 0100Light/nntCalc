#include <QApplication>
#include <QPushButton>
#include "calcmainwindow.hpp"
#include <memory>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto mainWindow = std::make_unique<CalcMainWindow>();
    mainWindow->show();

    return QApplication::exec();
}
