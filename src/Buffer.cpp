#include "Buffer.hpp"
#include "glibmm/refptr.h"

#include <fstream>
#include <string>
#include <vector>

namespace Slate
{

static int id_count = 0;

// TODO: inherit from Gtk::TextBuffer??
/**
 * @param id    unique id for this buffer
 * @param title title for this buffer, empty if the buffer is for a file
 * @param path  path to file opened by this buffer, empty string if 
 *              the buffer is not for a file
 */
Buffer::Buffer(std::string path)
{
    this->id = id_count++;

    // TODO error checking
    file.open(path);

    std::string cur_line;
    while (std::getline(file, cur_line)) {
        lines.push_back(cur_line);
    }
}

Buffer::~Buffer()
{
    file.close();
}

std::string Buffer::cat_lines()
{
    std::string out = "";

    for (std::string line : lines) {
        out.append(line + "\n");
    }

    return out;
}

}
