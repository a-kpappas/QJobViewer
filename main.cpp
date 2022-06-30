#include "qjobviewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QJobViewer w;
    w.show();
    auto root = w.centralWidget();
    QTabWidget* tabBar = root->findChild<QTabWidget *>("tabWidget");
    return a.exec();
}
