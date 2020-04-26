#include "button.h"

#include <iostream>


Button::Button(QWidget *parent) : CustomQLabel(parent)
{

}


void Button::mouseReleaseEvent(QMouseEvent* event)
{
    emit released();
}
