#include "treedude.hpp"
#include <chrono>
#include <thread>
#include <ncurses.h>

void Treedude::chopLeft()
{
    remove(27);
    remove(51);
    currentState = chop_left;
    draw(27);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    remove(27);
    currentState = idle_left;
    draw(27);
}
void Treedude::chopRight()
{
    remove(27);
    remove(51);
    currentState = chop_right;
    draw(51);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    remove(51);
    currentState = idle_right;
    draw(51);
}

void Treedude::draw(int xPos, int yPos)
{
    for (int i = 0; i < stateArray[currentState].size(); ++i)
    {
        mvaddstr(yPos, xPos, stateArray[currentState][i].c_str());
        ++yPos;
    }
    refresh();
}

void Treedude::remove(int xPos, int yPos)
{
    for (int i = 0; i < stateArray[currentState].size(); ++i)
    {
        int tempXPos = xPos;
        for (int j = 0; j < stateArray[currentState][i].size(); ++j)
        {
            mvaddstr(yPos, tempXPos, " ");
            ++tempXPos;
        }
        ++yPos;
    }
    refresh();
}