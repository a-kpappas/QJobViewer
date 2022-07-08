#ifndef QJOBVIEWER_H
#define QJOBVIEWER_H

#include <QMainWindow>

#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTabWidget>
#include <QFileDialog>
#include <QDebug>
#include <QJsonObject>

class JobGetter : public QWidget{
    Q_OBJECT
public:
    JobGetter(QWidget *parent = nullptr);
    ~JobGetter(){};
signals:
    void jsonLoaded(QJsonObject json);
private:
    QComboBox* m_urlInputCBox;
    QPushButton* m_viewButton;
    QLabel* m_displayLabel;
    QPushButton* m_fileButton;
    QFileDialog* m_fileDialog;
    void setURL();
    void loadFile();
};

class QJobViewer : public QMainWindow
{
    Q_OBJECT
public:
    QJobViewer(QWidget *parent = nullptr);
    ~QJobViewer(){};
signals:
    void urlUpdated(QUrl url);
    void jsonLoaded(QJsonObject json);

private:
    QWidget* central;
    JobGetter* inputField;
    QTabWidget* tabs;
};



#endif // QJOBVIEWER_H

