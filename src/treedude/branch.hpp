#ifndef BRANCH_HPP
#define BRANCH_HPP

#include <array>
#include <string>
#include "util.hpp"
#include <ncurses.h>

class Branch
{
public:
    enum sides
    {
        right,
        left
    };

private:
    std::array<std::array<std::string, 5>, 2> states{{{"     oOo", "     / oO", "   /--00oO", "--<   OOo", "   \\oOO"}, {"   o  o", " o0Oo--\\", "O0Oo  --\\", "oOOOo  /->-", "  o0O-/"}}};

    sides currentSide;

    Branch(sides side) : currentSide{side}
    {
        int xPos;
        int yPos;

        if (side == left)
        {
            draw(29, 1);
        }
        else
        {
            draw(52, 1);
        }
        refresh();
    }

    short height = 2;

    void draw(int xPos, int yPos)
    {
        for (int i = 0; i < 5; ++i)
        {
            mvaddstr(yPos, xPos, states[currentSide][i].c_str());
            ++yPos;
        }
    }

    void remove(int xPos, int yPos)
    {
        for (int i = 0; i < states[currentSide].size(); ++i)
        {
            int tempXPos = xPos;
            for (int j = 0; j < states[currentSide][i].size(); ++j)
            {
                mvaddstr(yPos, tempXPos, " ");
                ++tempXPos;
            }
            ++yPos;
        }
    }

public:
    static Branch *tryCreate()
    {
        if (getRand(2) == 1)
        {
            if (getRand(1))
            {
                return new Branch{left};
            }
            else
            {
                return new Branch{right};
            }
        }
        return nullptr;
    }

    bool getDanger() const { return height == 0; }
    bool decHeight()
    {
        --height;

        int xPos;
        int yPos;

        if (currentSide == left)
        {
            xPos = 29;
        }
        else
        {
            xPos = 52;
        }

        if (height == 1)
        {
            yPos = 7;
        }
        else
        {
            yPos = 13;
        }

        if (height < 0)
        {
            remove(xPos, yPos);
            return true;
        }

        remove(xPos, yPos - 6);

        draw(xPos, yPos);
        refresh();

        return false;
    }
    sides getSide() const { return currentSide; }
};

#endif