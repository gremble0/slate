#include "Buffer.hpp"
#include "gdkmm/event.h"

#include <fstream>
#include <string>
#include <vector>

namespace Slate
{

static int id_count = 0;

/**
 * @param id    unique id for this buffer
 * @param title title for this buffer, empty if the buffer is for a file
 * @param path  path to file opened by this buffer, empty string if 
 *              the buffer is not for a file
 */
Buffer::Buffer(std::string title, std::string path)
{
    this->title = title;
    this->id = id_count++;

    // If the buffer is not for a file return early
    if (path == "") {
        return;
    }

    // Otherwise read the file contents into the lines vector

    // TODO error checking
    file.open(path);

    std::string cur_line;
    while (std::getline(file, cur_line)) {
        set_text(get_text() + cur_line + "\n");
    }
}

Buffer::~Buffer()
{
    file.close();
}

}
