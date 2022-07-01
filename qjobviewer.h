#ifndef QJOBVIEWER_H
#define QJOBVIEWER_H

#include <QMainWindow>

#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTabWidget>
#include <QDebug>

class QJobViewer : public QMainWindow
{
    Q_OBJECT
public:
    QJobViewer(QWidget *parent = nullptr);
    ~QJobViewer(){};
signals:
    void urlUpdated(QUrl url);
private:
    QWidget* central;
    QWidget* inputField;
    QTabWidget* tabs;
};

class JobGetter : public QWidget{
    Q_OBJECT
public:
    JobGetter(QWidget *parent = nullptr);
    ~JobGetter(){};
private:
    QComboBox* m_urlInputCBox;
    QPushButton* m_viewButton;
    QLabel* m_displayLabel;
    void setURL();
};

#endif // QJOBVIEWER_H

