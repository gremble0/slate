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

enum class SplitMethod
{
    REPLACE,
    TOP,
    RIGHT,
    BOTTOM,
    LEFT,
};

class Window : public Gtk::Window 
{
public:
    Window();
    void OpenBuffer(std::shared_ptr<Buffer> buffer, SplitMethod sm);
protected:
    // TODO: integrate our types with the GTK types
    std::vector<std::shared_ptr<Buffer>> open_buffers;
    // std::shared_ptr<Buffer> active_buffer;
    std::vector<std::shared_ptr<Buffer>> visible_buffers;
    Gtk::ScrolledWindow scrolled_window;
    Gtk::TextView text_view;
    Gtk::Box view;
};

}
