#pragma once

#include <fstream>
#include <string>
#include <vector>

class SlateBuffer
{
public:
    SlateBuffer(std::string title = "[No Name]", std::string path = "");
    ~SlateBuffer();
    std::string get_lines();
    std::string title;
protected:
    int id;
    std::fstream file;
    std::vector<std::string> lines;
};
