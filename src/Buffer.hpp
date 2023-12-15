#pragma once

#include "Cursor.hpp"
#include "gtkmm/textbuffer.h"

#include <fstream>
#include <string>
#include <vector>

namespace Slate
{

class Buffer : public Gtk::TextBuffer
{
public:
    Buffer(std::string path = "");
    ~Buffer();

    void move_back_char();
    void move_forward_char();
    void move_backward_line();
    void move_forward_line();
protected:
    std::string title;

    int id;
    std::fstream file;
    std::vector<std::string> lines;
    Cursor cursor;
};

}
