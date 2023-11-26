#include <gtkmm.h>
#include "ui.hpp"

class MyWindow : public Gtk::Window 
{
public:
    MyWindow();
};

MyWindow::MyWindow()
{
    set_title("Basic application");
    set_default_size(WINDOW_WIDTH, WINDOW_HEIGHT);
}

int main(int argc, char **argv)
{
    auto app = Gtk::Application::create("Slate");
    return app->make_window_and_run<MyWindow>(argc, argv);
}
