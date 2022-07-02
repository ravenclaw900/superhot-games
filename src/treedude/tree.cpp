#include "tree.hpp"
#include "treesegment.hpp"

Tree::Tree()
{
    segments[0] = new TreeSegment(40, LINES - 7);
    segments[1] = new TreeSegment(40, LINES - 13);
    segments[2] = new TreeSegment(40, LINES - 19);
}

void Tree::moveDown()
{
    delete segments[0];
    segments[0] = segments[1];
    segments[1] = segments[2];
    segments[2] = new TreeSegment(40, LINES - 19);
    segments[0]->draw(40, LINES - 7);
    segments[1]->draw(40, LINES - 13);
}
