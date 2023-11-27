#include <vector>

#include "glibmm/refptr.h"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include "gtkmm/scrolledwindow.h"
#include "gtkmm/textbuffer.h"
#include "gtkmm/textview.h"
#include "SlateBuffer.hpp"
#include "SlateWindow.hpp"

namespace Slate
{

// TODO: Slate::Window, Slate::Buffer, etc
SlateWindow::SlateWindow()
{
    set_title("Slate");
    set_child(view);
    set_default_size(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    // TODO: respect user config
    scrolled_window.set_child(text_view);
    scrolled_window.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
    scrolled_window.set_expand();
    view.append(scrolled_window);

    SlateBuffer buffer = SlateBuffer("Welcome to Slate");
    buffers.push_back(&buffer);
    active_buffer = Gtk::TextBuffer::create();
    SetActiveBuffer(buffer);
}

void SlateWindow::SetActiveBuffer(SlateBuffer &buffer)
{
    active_buffer->set_text(buffer.get_lines());
    text_view.set_buffer(active_buffer);
}

}
