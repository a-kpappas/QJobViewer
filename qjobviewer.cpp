#include "qjobviewer.h"
#include "./ui_qjobviewer.h"

QJobViewer::QJobViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QJobViewer)
{
    ui->setupUi(this);
}

QJobViewer::~QJobViewer()
{
    delete ui;
}

