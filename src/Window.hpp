#include "Buffer.hpp"
#include "gtkmm/box.h"
#include "gtkmm/textview.h"
#include "gtkmm/window.h"
#include "gtkmm/scrolledwindow.h"

namespace Slate
{

#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT 600

class Window : public Gtk::Window 
{
public:
    Window();
    void SetActiveBuffer(Buffer &buffer);
protected:
    // TODO: integrate our types with the GTK types
    std::vector<Buffer*> buffers;
    Gtk::ScrolledWindow scrolled_window;
    Gtk::TextView text_view;
    Gtk::Box view;
    Glib::RefPtr<Gtk::TextBuffer> active_buffer;
};

}
