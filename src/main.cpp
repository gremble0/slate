#include "Window.hpp"

#include <sol/sol.hpp>
#include <gtkmm.h>

using namespace Slate;

int main(int argc, char **argv)
{
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    auto app = Gtk::Application::create("org.gtkmm.slate");
    return app->make_window_and_run<Window>(argc, argv);
}
