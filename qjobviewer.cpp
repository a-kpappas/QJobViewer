#include "qjobviewer.h"
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QStandardPaths>

QJobViewer::QJobViewer(QWidget *parent)
    : QMainWindow(parent)
{
    central =  new QWidget(this);
    this->setCentralWidget(central);

    auto layout = new QGridLayout(central);
    // Widget for loading json to the model
    inputField = new JobGetter;
    layout->addWidget(inputField);
    connect(inputField,&JobGetter::jsonLoaded,this,&QJobViewer::jsonLoaded);

    // Tab Widget
    //1. Set up tab widget
    tabs = new QTabWidget;

    //1.a. Set up settings tab
    auto settingsPage = new QWidget;
    auto settingsGrid = new QVBoxLayout(settingsPage);
    settingsView = new QTableView();
    settingsGrid->addWidget(settingsView);
    tabs->addTab(settingsPage,"Settings");

    //2. Finish tab widget
    layout->addWidget(tabs);
    central->setLayout(layout);
    // this->setLayout(layout);

}

JobGetter::JobGetter(QWidget *parent)
    : QWidget(parent)
{
    auto fieldLayout = new QGridLayout(this);

    m_urlInputCBox = new QComboBox;
    m_urlInputCBox->setEditable(true);
    m_urlInputCBox->setPlaceholderText(tr("Please type job URL"));
    m_urlInputCBox->setInsertPolicy(QComboBox::InsertAtTop);
    fieldLayout->addWidget(m_urlInputCBox,0,0);

    m_viewButton = new QPushButton(tr("Get Job"));
    m_viewButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    fieldLayout->addWidget(m_viewButton,0,1);
    connect(m_viewButton,&QPushButton::clicked,this,&JobGetter::setURL);

    auto m_fileDialog = new QFileDialog(this);
    m_fileDialog->setFileMode(QFileDialog::ExistingFile);

    auto m_fileButton = new QPushButton(tr("Open JobCSV"));
    m_fileButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    fieldLayout->addWidget(m_fileButton,0,2);
    connect(m_fileButton,&QPushButton::clicked,this,&JobGetter::loadFile);

    m_displayLabel = new QLabel("");
    fieldLayout->addWidget(m_displayLabel,1,0);
    m_displayLabel->setText("");

}

void JobGetter::loadFile(){
    QString fileName;
#ifdef QT_DEBUG
    fileName = "/home/apappas/qa-dev/QJobViewer/test.json";
#else
    fileName = QFileDialog::getOpenFileName(this,
    tr("Open JSON"), QDir::currentPath(), tr("JSON Files (*.json)"));
#endif
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        qWarning()<<"Couldn't open file "<<fileName;
        m_displayLabel->setText("Couldn't open file "+fileName);
        return;
    }
    QByteArray data = file.readAll();
    QJsonParseError err;
    auto doc = QJsonDocument::fromJson(data,&err);
    if (doc.isNull()){
        qWarning()<<err.errorString();
        m_displayLabel->setText(err.errorString());
    }
    emit jsonLoaded(doc.object());
}


void JobGetter::setURL()
{
    auto txt = m_urlInputCBox->currentText();
    auto url = QUrl(txt);
    qWarning()<<"Validity:"<<url.isValid()<<" Content:"<<url;
    if (url.isValid()){
        m_displayLabel->setText(txt);
        m_urlInputCBox->insertItem(0,txt);
    } else {
        m_displayLabel->setText("Invalid URL.");
    }
}
