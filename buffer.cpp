#include <string>
#include <vector>

class SlateBuffer
{
    public:
        SlateBuffer(int id, std::string title = "", std::string path = "");
    protected:
        std::string basename();

        int id;
        std::string title;
        std::string path;
        std::vector<std::string> lines;
};

/**
 * @param id    unique id for this buffer
 * @param title title for this buffer, empty if the buffer is for a file
 * @param path  path to file opened by this buffer, empty string if 
 *              the buffer is not for a file
 */
SlateBuffer::SlateBuffer(int id, std::string title, std::string path)
{
    this->id = id;

    if (title != "") {
        this->title = title;
    }

    if (path != "") {
        this->path = path;
    }
}
