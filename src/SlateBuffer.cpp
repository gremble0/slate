#include <fstream>
#include <string>
#include <vector>

#include "SlateBuffer.hpp"

static int id_count = 0;

// TODO: inherit from Gtk::TextBuffer??
/**
 * @param id    unique id for this buffer
 * @param title title for this buffer, empty if the buffer is for a file
 * @param path  path to file opened by this buffer, empty string if 
 *              the buffer is not for a file
 */
SlateBuffer::SlateBuffer(std::string title, std::string path)
{
    this->id = id_count++;
    this->title = title;

    // TODO error checking
    file.open(path);

    std::string cur_line;
    while (std::getline(file, cur_line)) {
        lines.push_back(cur_line);
    }
}

SlateBuffer::~SlateBuffer()
{
    file.close();
}

std::string SlateBuffer::get_lines()
{
    std::string out = "";

    for (std::string line : lines) {
        out.append(line + "\n");
    }

    return out;
}
