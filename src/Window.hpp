#include "Buffer.hpp"
#include "gdkmm/enums.h"
#include "gtkmm/box.h"
#include "gtkmm/cssprovider.h"
#include "gtkmm/textview.h"
#include "gtkmm/widget.h"
#include "gtkmm/window.h"
#include "gtkmm/scrolledwindow.h"

#include <memory>

namespace Slate
{

#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT 600
// TODO namespace instead? also: for platform neutrality alternative for control? cmd?
#define SHIFT_MASK Gdk::ModifierType::SHIFT_MASK
#define CONTROL_MASK Gdk::ModifierType::CONTROL_MASK
#define ALT_MASK Gdk::ModifierType::ALT_MASK

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
    void open_buffer(std::shared_ptr<Buffer> buffer, SplitMethod sm);
protected:
    std::vector<std::shared_ptr<Buffer>> open_buffers;
    Gtk::ScrolledWindow scrolled_window;
    Gtk::TextView text_view;
    Gtk::Box view;
    std::shared_ptr<Gtk::CssProvider> css_provider;

    bool handle_event(guint keyval, guint keycode, Gdk::ModifierType state);
};

}
