/*
 * Copyright (C) 2020  Spencer Davis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


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
