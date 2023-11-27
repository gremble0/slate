namespace Slate
{

class Cursor
{
public:
    Cursor(int row, int col);
    Cursor();
    void move(int row, int col);

    int row;
    int col;
};

}
