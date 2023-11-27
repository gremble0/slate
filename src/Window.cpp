#include "Buffer.hpp"
#include "Window.hpp"
#include "glibmm/refptr.h"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include "gtkmm/scrolledwindow.h"
#include "gtkmm/textview.h"

#include <vector>

namespace Slate
{

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

    active_buffer = Buffer::create();
    buffers.push_back(active_buffer);
    SetActiveBuffer(active_buffer);
}

void Window::SetActiveBuffer(std::shared_ptr<Buffer> buffer)
{
    active_buffer->set_text(buffer->cat_lines());
    text_view.set_buffer(buffer);
}

}
