#include "qjobviewer.h"
#include "jobmodel.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "QJobViewer_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    QJobViewer w;
    JobModel model;
    QObject::connect(&w,&QJobViewer::jsonLoaded,&model,&JobModel::load);
    w.show();
    return a.exec();
}
