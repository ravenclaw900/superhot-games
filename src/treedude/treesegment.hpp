#ifndef TREESEGMENT_HPP
#define TREESEGMENT_HPP

#include <array>
#include <ncurses.h>
#include <string>

class TreeSegment
{
private:
    std::array<char, 5> chars{'{', '}', '\\', '/', '|'};
    std::array<std::string, 6> segment{};

public:
    void draw(int xPos, int yPos);

    TreeSegment(int xPos, int yPos);
};

#endif