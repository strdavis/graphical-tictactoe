#pragma once

#include "custom-qwidget.h"

class Button;
class CustomQLabel;


class TitleScreen : public CustomQWidget
{
    Q_OBJECT

public:
    TitleScreen(QWidget *parent = nullptr);

public slots:
    void enable() override;

private slots:
    void playClicked();

private:
    void disable() override;

    CustomQLabel *background;
    Button *play;
};
