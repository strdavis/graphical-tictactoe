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
