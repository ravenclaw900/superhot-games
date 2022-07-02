#include "treedude.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include <ncurses.h>
#include <iostream>
#include <chrono>
#include <thread>

void initWindow()
{
    initscr();
    box(stdscr, 0, 0);
    mvaddstr(0, 3, "TREE");
    mvaddstr(0, 8, "DUDE");
    mvaddstr(0, 13, "TREE");
    mvaddstr(0, 18, "DUDE");
    mvaddstr(0, 23, "DUDE");
    mvaddstr(0, 28, "by");
    mvaddstr(0, 31, "ravenclaw900");

    keypad(stdscr, true);
    noecho();

    refresh();
}

bool shouldDie(Branch *branch, Treedude const &treedude)
{
    if (branch->getDanger())
    {
        Branch::sides branchSide = branch->getSide();
        Treedude::states treedudeSide = treedude.getState();
        if ((treedudeSide == Treedude::states::idle_left && branchSide == Branch::left) ||
            (treedudeSide == Treedude::states::idle_right && branchSide == Branch::right))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    initWindow();

    Treedude treedude;
    Tree tree;
    Branch *branch = Branch::tryCreate();

    while (true)
    {
        if (branch && shouldDie(branch, treedude))
        {
            delete branch;
            break;
        }
        switch (getch())
        {
        case KEY_LEFT:
            treedude.chopLeft();
            break;
        case KEY_RIGHT:
            treedude.chopRight();
            break;
        }
        tree.moveDown();
        if (branch)
        {
            if (shouldDie(branch, treedude))
            {
                delete branch;
                break;
            }
            if (branch->decHeight())
            {
                delete branch;
                branch = nullptr;
            }
        }
        else
        {
            branch = Branch::tryCreate();
        }
    }

    endwin();

    return 0;
}