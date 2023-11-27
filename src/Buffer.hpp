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
    std::string title;

    Buffer(std::string title = "", std::string path = "");
    ~Buffer();
    std::string cat_lines();
protected:
    int id;
    std::fstream file;
    std::vector<std::string> lines;
    Cursor cursor;
};

}
