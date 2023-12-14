#include "Buffer.hpp"
#include "Window.hpp"
#include "glibmm/refptr.h"
#include "gtkmm/box.h"
#include "gtkmm/cssprovider.h"
#include "gtkmm/enums.h"
#include "gtkmm/eventcontrollerkey.h"
#include "gtkmm/scrolledwindow.h"
#include "gtkmm/textview.h"
#include "sigc++/functors/mem_fun.h"

#include <iostream>
#include <memory>
#include <vector>

namespace Slate
{

Window::Window()
{
    // Set some basic config
    this->set_title("Slate");
    this->set_default_size(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    // Initialize basic window widgets
    // TODO: respect user config
    this->scrolled_window.set_child(text_view);
    this->scrolled_window.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
    this->scrolled_window.set_expand();
    this->view.append(scrolled_window);
    this->set_child(view);

    // CSS styling
    this->css_provider = Gtk::CssProvider::create();
    css_provider->load_from_path("window.css");
    this->text_view.add_css_class("scrolled-window");
    this->text_view.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Open empty buffer
    auto empty_buffer = std::make_shared<Buffer>("", "window.css"); // temporary random file
    this->open_buffer(empty_buffer, SplitMethod::REPLACE);

    // Handle events (keyboard input)
    auto controller = Gtk::EventControllerKey::create();
    controller->signal_key_pressed().connect(
        sigc::mem_fun(*this, &Window::handle_event), false
    );
    add_controller(controller);
}

/**
 * Opens a new buffer by adding it to the list of open buffers and visible buffers
 */
void Window::open_buffer(std::shared_ptr<Buffer> buffer, SplitMethod sm)
{
    // TODO: handle splitting and replacing buffers
    open_buffers.push_back(buffer);
    text_view.set_buffer(buffer);
}

/**
 * @return true if event was handled, false if not
 */
bool Window::handle_event(guint keyval, guint, Gdk::ModifierType state)
{
    // TODO: hook up with user config - maybe hard code some keybindings
    std::cout << keyval << std::endl;
    return false;
}

}
