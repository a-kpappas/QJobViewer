#include "buttonedcombobox.h"
#include "ui_buttonedcombobox.h"

ButtonedComboBox::ButtonedComboBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonedComboBox)
{
    ui->setupUi(this);
}

ButtonedComboBox::~ButtonedComboBox()
{
    delete ui;
}
