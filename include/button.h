#pragma once

#include "custom-qlabel.h"

class CustomQMovie;


// Adds click-detection to CustomQLabels
class Button : public CustomQLabel
{  
    Q_OBJECT

public:
    Button(QWidget *parent = nullptr);

protected:
    void mouseReleaseEvent(QMouseEvent* event);

signals:
    void released();
};
