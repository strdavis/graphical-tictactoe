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

#include <QLabel>

class CustomQMovie;


// Provides streamlined handling of animations on QLabels.
class CustomQLabel : public QLabel
{
    Q_OBJECT

public:
    CustomQLabel(QWidget *parent = nullptr);

    void setAnimation(const char *path);
    void startAnimation();
    void stopAnimation();
    void pauseAnimation();
    int getAnimationDuration();

public slots:
    void playAnimationOnce();

protected:
    CustomQMovie *animation;

private slots:
    void enableGlobalInput();

private:
    void disableGlobalInputFor(int duration);
};
