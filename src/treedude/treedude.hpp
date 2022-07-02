#ifndef TREEDUDE_HPP
#define TREEDUDE_HPP

#include <array>
#include <string>
#include <ncurses.h>

class Treedude
{
public:
    enum states
    {
        idle_right,
        idle_left,
        chop_right,
        chop_left,
        dead
    };

private:
    std::array<std::array<std::string, 6>, 4> stateArray{{{"      ###", "[   ]#####", "  | _|- -|_", "  |/  \\_/  \\", "  ||_______|", "   |___|___|"},
                                                          {"    ###", "   #####[   ]", "  _|- -|_ |", " /  \\_/  \\|", " |_______||", " |___|___|"},
                                                          {"        ###", "       #####", "      _|o o|_", "     /  \\_/  \\", "===-----   __|", "     |___|___|"},
                                                          {"   ###", "  #####", " _|o o|_", "/  \\_/  \\", "|__   -----===", "|___|___|"}}};

    states currentState = idle_left;

    void draw(int xPos, int yPos = LINES - 7);

    void remove(int xPos, int yPos = LINES - 7);

public:
    states getState() const { return currentState; }
    Treedude() { draw(26); }
    void chopLeft();
    void chopRight();
};

#endif