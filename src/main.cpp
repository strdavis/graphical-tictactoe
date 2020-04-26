#include "window.h"

#include <QApplication>


int main(int argc, char **argv)
{
    // Initialize event handler
    QApplication app (argc, argv);

    Window window;
    window.show();

    // Activate event handler
    return app.exec();
}
