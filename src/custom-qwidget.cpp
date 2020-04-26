#include "custom-qwidget.h"

#include <iostream>

#include "custom-qlabel.h"
#include "button.h"


CustomQWidget::CustomQWidget(QWidget *parent) : QWidget(parent)
{
    // Match size to parent widget().
    setGeometry(parentWidget()->rect());
}


CustomQLabel *CustomQWidget::addLabel(int x, int y, int w, int h)
{
    CustomQLabel *label = new CustomQLabel(this);
    label->setGeometry(x, y, w, h);

    return label;
}


Button *CustomQWidget::addButton(int x, int y, int w, int h)
{
    Button *button = new Button(this);
    button->setGeometry(x, y, w, h);

    return button;
}


void CustomQWidget::enable()
{
    setEnabled(true);

    raise();
}


void CustomQWidget::disable()
{
    setEnabled(false);

    lower();
}
