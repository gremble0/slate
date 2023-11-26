#include <gtkmm.h>
#include "gtkmm/button.h"
#include "ui.hpp"
#include "SlateBuffer.cpp"

class SlateWindow : public Gtk::Window 
{
    public:
        SlateWindow();
        void MakeButtonBox();
    protected:
        void on_button_clicked();
        Gtk::Button slate_button;
};

SlateWindow::SlateWindow()
{
    set_title("Slate");
    set_default_size(WINDOW_WIDTH, WINDOW_HEIGHT);
    SlateBuffer buffer = SlateBuffer("title", "/home/herman/.gitignore");
}

int main(int argc, char **argv)
{ 
    // Idk what the parameter means, from: https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/chapter-basics.html
    auto app = Gtk::Application::create("org.gtkmm.slate");
    return app->make_window_and_run<SlateWindow>(argc, argv);
}
