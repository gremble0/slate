#pragma once

#include "Cursor.hpp"
#include "gtkmm/textbuffer.h"

#include <fstream>
#include <memory>
#include <string>
#include <vector>

namespace Slate
{

class Buffer : public Gtk::TextBuffer
{
public:
    Buffer(std::string path = "");
    ~Buffer();

    static std::shared_ptr<Buffer> create() {
        return std::make_shared<Buffer>();
    }
    std::string cat_lines();
protected:
    int id;
    std::fstream file;
    std::vector<std::string> lines;
    Cursor cursor;
};

}
