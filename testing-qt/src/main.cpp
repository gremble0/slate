#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <vector>

namespace Slate
{

// BUFFER
class Buffer : public QWidget
{
    Q_OBJECT

public:
    Buffer(QWidget *parent = nullptr);

private:
    QString fileName = "";
};

Buffer::Buffer(QWidget *parent)
    : QWidget(parent)
{
}

// WINDOW
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    MainWindow *ui;
    std::vector<Buffer> buffers;
};

MainWindow::MainWindow(QWidget *parent)
{
    this->buffers.push_back(new Buffer());
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // Create a QMainWindow instance
    QMainWindow window;

    // Set window properties and show the window
    window.setWindowTitle("Text Editor");
    window.setGeometry(100, 100, 800, 600);
    window.show();

    // Run the application event loop
    return app.exec();
}

}
