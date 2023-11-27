#include <vector>

#include "glibmm/refptr.h"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include "gtkmm/scrolledwindow.h"
#include "gtkmm/textbuffer.h"
#include "gtkmm/textview.h"
#include "Buffer.hpp"
#include "Window.hpp"

namespace Slate
{

// TODO: Slate::Window, Slate::Buffer, etc
Window::Window()
{
    set_title("Slate");
    set_child(view);
    set_default_size(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    // TODO: respect user config
    scrolled_window.set_child(text_view);
    scrolled_window.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
    scrolled_window.set_expand();
    view.append(scrolled_window);

    Buffer buffer = Buffer("Welcome to Slate");
    buffers.push_back(&buffer);
    active_buffer = Gtk::TextBuffer::create();
    SetActiveBuffer(buffer);
}

void Window::SetActiveBuffer(Buffer &buffer)
{
    active_buffer->set_text(buffer.get_lines());
    text_view.set_buffer(active_buffer);
}

}
