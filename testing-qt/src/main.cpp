#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <vector>

#include "MainWindow.hpp"
#include "Buffer.hpp"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // Create a QMainWindow instance
    MainWindow window;

    // Set window properties and show the window
    window.setWindowTitle("Text Editor");
    window.setGeometry(100, 100, 800, 600);
    window.show();

    // Run the application event loop
    return app.exec();
}
