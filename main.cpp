#include <gtkmm.h>
#include <iostream>
#include "gtkmm/box.h"
#include "gtkmm/button.h"
#include "gtkmm/label.h"
#include "gtkmm/object.h"
#include "ui.hpp"

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
    MakeButtonBox();
}

void SlateWindow::MakeButtonBox()
{
    //Create Label widget:
    auto label = Gtk::make_managed<Gtk::Label>("cool button for slate 8)");
    label->set_expand(true);

    //Put it in a Box:
    auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
    hbox->append(*label);

    // Add box to button and attatch on click event
    slate_button.set_child(*hbox);
    slate_button.signal_clicked().connect(sigc::mem_fun(*this, &SlateWindow::on_button_clicked));

    slate_button.set_margin(10);
    set_child(slate_button);
}

void SlateWindow::on_button_clicked()
{
    std::cout << "Button clicked" << std::endl;
}

int main(int argc, char **argv)
{ 
    // Idk what the parameter means, from: https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/chapter-basics.html
    auto app = Gtk::Application::create("org.gtkmm.slate");
    return app->make_window_and_run<SlateWindow>(argc, argv);
}
