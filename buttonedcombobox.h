#ifndef BUTTONEDCOMBOBOX_H
#define BUTTONEDCOMBOBOX_H

#include <QWidget>

namespace Ui {
class ButtonedComboBox;
}

class ButtonedComboBox : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonedComboBox(QWidget *parent = nullptr);
    ~ButtonedComboBox();

private:
    Ui::ButtonedComboBox *ui;
};

#endif // BUTTONEDCOMBOBOX_H
