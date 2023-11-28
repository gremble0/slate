#include "Buffer.hpp"
#include "gdkmm/enums.h"
#include "gtkmm/box.h"
#include "gtkmm/textview.h"
#include "gtkmm/window.h"
#include "gtkmm/scrolledwindow.h"

#include <memory>

namespace Slate
{

#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT 600
// TODO namespace instead?
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
    void OpenBuffer(std::shared_ptr<Buffer> buffer, SplitMethod sm);
protected:
    // TODO: integrate our types with the GTK types
    std::vector<std::shared_ptr<Buffer>> open_buffers;
    // std::shared_ptr<Buffer> active_buffer;
    std::vector<std::shared_ptr<Buffer>> visible_buffers;
    Gtk::ScrolledWindow scrolled_window;
    Gtk::TextView text_view;
    Gtk::Box view;

    bool handle_event(guint keyval, guint keycode, Gdk::ModifierType state);
};

}
