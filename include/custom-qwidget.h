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


#pragma once

#include <QWidget>

class CustomQLabel;
class Button;


// Provides functions for controlling child widgets as a group.
// --> Contains virtual functions which can be overwritten to
// --> specify behaviour of child widgets as a group
// --> when parent is enabled / disabled.
// Provides functions for easily adding CustomQLabels and Buttons as child widgets.
class CustomQWidget : public QWidget
{
    Q_OBJECT

public:
    CustomQWidget(QWidget *parent = nullptr);

public slots:
    virtual void enable();

protected:
    CustomQLabel *addLabel(int x, int y, int w, int h);
    Button *addButton(int x, int y, int w, int h);
    virtual void disable();

signals:
    void disabled();
};
