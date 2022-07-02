#include "treesegment.hpp"
#include <ncurses.h>
#include "util.hpp"

void TreeSegment::draw(int xPos, int yPos)
{
    for (int i = 0; i < 6; ++i)
    {
        mvaddstr(yPos, xPos, segment[i].c_str());
        ++yPos;
    }
    refresh();
}

TreeSegment::TreeSegment(int xPos, int yPos)
{
    for (int i = 0; i < 6; ++i)
    {
        segment[i] = "|          |";
    }
    for (int i = 0; i < 10; ++i)
    {
        int tempX = getRand(11);
        int tempY = getRand(5);
        char character;
        if (tempX == 0)
        {
            character = '{';
        }
        else if (tempX == 11)
        {
            character = '}';
        }
        else
        {
            character = chars[getRand(4)];
        }
        segment[tempY][tempX] = character;
    }
    draw(xPos, yPos);
}
