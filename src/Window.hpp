#include "Buffer.hpp"
#include "gtkmm/box.h"
#include "gtkmm/textview.h"
#include "gtkmm/window.h"
#include "gtkmm/scrolledwindow.h"
#include <memory>

namespace Slate
{

#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT 600

class Window : public Gtk::Window 
{
public:
    Window();
    void SetActiveBuffer(std::shared_ptr<Buffer> buffer);
protected:
    // TODO: integrate our types with the GTK types
    std::vector<std::shared_ptr<Buffer>> buffers;
    std::shared_ptr<Buffer> active_buffer;
    Gtk::ScrolledWindow scrolled_window;
    Gtk::TextView text_view;
    Gtk::Box view;
};

}
