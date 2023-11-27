#include <gtkmm.h>
#include "SlateWindow.hpp"

using namespace Slate;

int main(int argc, char **argv)
{ 
    // Idk what the parameter means, from: https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/chapter-basics.html
    auto app = Gtk::Application::create("org.gtkmm.slate");
    return app->make_window_and_run<SlateWindow>(argc, argv);
}
