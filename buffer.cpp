#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

static int id_count = 0;

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

/**
 * @param id    unique id for this buffer
 * @param title title for this buffer, empty if the buffer is for a file
 * @param path  path to file opened by this buffer, empty string if 
 *              the buffer is not for a file
 */
SlateBuffer::SlateBuffer(std::string title, std::string path)
{
    this->id = id_count++;

    if (title != "") {
        this->title = title;
    }

    if (path != "") {
        this->path = path;
    }

    // TODO error checking
    // TODO check if in and out flags are necessary
    file.open(path, std::ios::in | std::ios::out);

    std::string cur_line;
    while (std::getline(file, cur_line)) {
        lines.push_back(cur_line);
    }

    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }
}

SlateBuffer::~SlateBuffer()
{
    file.close();
}
