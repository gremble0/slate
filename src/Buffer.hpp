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

    std::string title;
protected:
    int id;
    std::fstream file;
    std::vector<std::string> lines;
    Cursor cursor;
};

}
