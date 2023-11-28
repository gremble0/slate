#include "Buffer.hpp"
#include "Window.hpp"
#include "glibmm/refptr.h"
#include "gtkmm/box.h"
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
    set_title("Slate");
    set_default_size(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    // Initialize basic window widgets
    // TODO: respect user config
    scrolled_window.set_child(text_view);
    scrolled_window.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
    scrolled_window.set_expand();
    view.append(scrolled_window);
    set_child(view);

    // Open empty buffer
    std::shared_ptr<Buffer> empty_buffer = std::make_shared<Buffer>("", "/home/herman/.gitignore"); // temporary random file
    OpenBuffer(empty_buffer, SplitMethod::REPLACE);

    // Handle events (keyboard input)
    std::shared_ptr<Gtk::EventControllerKey> controller = Gtk::EventControllerKey::create();
    controller->signal_key_pressed().connect(
        sigc::mem_fun(*this, &Window::handle_event), false
    );
    add_controller(controller);
}

/**
 * Opens a new buffer by adding it to the list of open buffers and visible buffers
 */
void Window::OpenBuffer(std::shared_ptr<Buffer> buffer, SplitMethod sm)
{
    // TODO: handle splitting and replacing buffers
    visible_buffers.push_back(buffer);
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
