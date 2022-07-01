#include "qjobviewer.h"

QJobViewer::QJobViewer(QWidget *parent)
    : QMainWindow(parent)
{
    central = new QWidget(this);
    this->setCentralWidget(central);
    auto layout = new QGridLayout(central);

    inputField = new JobGetter;
    layout->addWidget(inputField);

    tabs = new QTabWidget;
    auto settingsPage = new QWidget;
    auto placeholder1 = new QLabel("settings placeholder",settingsPage);
    tabs->addTab(settingsPage,"Settings");
    layout->addWidget(tabs);
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

    m_viewButton = new QPushButton(tr("View Job"));
    m_viewButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    fieldLayout->addWidget(m_viewButton,0,1);
    connect(m_viewButton,&QPushButton::clicked,this,&JobGetter::setURL);

    m_displayLabel = new QLabel("");
    fieldLayout->addWidget(m_displayLabel,1,0);

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
