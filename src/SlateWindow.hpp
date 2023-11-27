#include "SlateBuffer.hpp"
#include "gtkmm/box.h"
#include "gtkmm/textview.h"
#include "gtkmm/window.h"
#include "gtkmm/scrolledwindow.h"

namespace Slate
{

#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT 600

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

}
