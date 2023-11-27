#include "Cursor.hpp"

namespace Slate
{

Cursor::Cursor()
{
    this->row = 0;
    this->col = 0;
}

Cursor::Cursor(int row, int col)
{
    this->row = row;
    this->col = col;
}

void Cursor::move(int row, int col)
{
    this->row = row;
    this->col = col;
}

}
