#include <gtkmm.h>
#include <vector>

#include "glibmm/refptr.h"
#include "gtkmm/enums.h"
#include "gtkmm/scrolledwindow.h"
#include "gtkmm/textbuffer.h"
#include "gtkmm/textview.h"
#include "ui.hpp"
#include "SlateBuffer.hpp"

// TODO: Slate::Window, Slate::Buffer, etc
class SlateWindow : public Gtk::Window 
{
    public:
        SlateWindow();
        void SetActiveBuffer(SlateBuffer &buffer);
    protected:
        // TODO: integrate our types with the GTK types
        std::vector<SlateBuffer*> buffers;
        Gtk::ScrolledWindow scrolled_window;
        Gtk::TextView text_view;
        Gtk::Box view;
        Glib::RefPtr<Gtk::TextBuffer> active_buffer;
};

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

int main(int argc, char **argv)
{ 
    // Idk what the parameter means, from: https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/chapter-basics.html
    auto app = Gtk::Application::create("org.gtkmm.slate");
    return app->make_window_and_run<SlateWindow>(argc, argv);
}
