#include "Window.hpp"

#include <sol/sol.hpp>
#include <gtkmm.h>

using namespace Slate;

int main(int argc, char **argv)
{ 
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    // Idk what the parameter means, from: https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/chapter-basics.html
    auto app = Gtk::Application::create("org.gtkmm.slate");
    return app->make_window_and_run<Window>(argc, argv);
}
