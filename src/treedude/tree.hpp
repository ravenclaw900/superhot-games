#ifndef TREE_HPP
#define TREE_HPP

#include <array>
#include "treesegment.hpp"

class Tree
{
private:
    std::array<TreeSegment *, 3> segments{};

public:
    Tree();
    ~Tree()
    {
        for (auto i : segments)
        {
            delete i;
        }
    }

    void moveDown();
};

#endif