#pragma once

#include <fstream>
#include <string>
#include <vector>

class SlateBuffer
{
public:
    SlateBuffer(std::string title = "", std::string path = "");
    ~SlateBuffer();
    std::string title;
    std::string path;
protected:
    int id;
    std::fstream file;
    std::vector<std::string> lines;
};
