#include "Buffer.hpp"
#include "Window.hpp"
#include "glibmm/refptr.h"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include "gtkmm/scrolledwindow.h"
#include "gtkmm/textview.h"

#include <memory>
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

    auto empty_buffer = std::make_shared<Buffer>("/home/herman/.gitignore");
    OpenBuffer(empty_buffer, SplitMethod::REPLACE);
}

void Window::OpenBuffer(std::shared_ptr<Buffer> buffer, SplitMethod sm)
{
    visible_buffers.push_back(buffer);
    open_buffers.push_back(buffer);
    // buffer->set_text(buffer->cat_lines());
    text_view.set_buffer(buffer);
}

}
