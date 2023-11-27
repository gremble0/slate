#pragma once

#include "Cursor.hpp"

#include <fstream>
#include <string>
#include <vector>

namespace Slate
{

class Buffer
{
public:
    Buffer(std::string title = "[No Name]", std::string path = "");
    ~Buffer();
    std::string cat_lines();

    std::string title;
protected:
    int id;
    std::fstream file;
    std::vector<std::string> lines;
    Cursor cursor;
};

}
