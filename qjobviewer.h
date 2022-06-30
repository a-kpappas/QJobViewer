#ifndef QJOBVIEWER_H
#define QJOBVIEWER_H

#include <QMainWindow>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class QJobViewer; }
QT_END_NAMESPACE

class QJobViewer : public QMainWindow
{
    Q_OBJECT

public:
    QJobViewer(QWidget *parent = nullptr);
    ~QJobViewer();

public slots:
    void setJobURL(QString url);

signals:
    void urlUpdated(QUrl url);

private slots:
    void updateURL();

private:
    Ui::QJobViewer *ui;
    QNetworkAccessManager manager;
};
#endif // QJOBVIEWER_H
