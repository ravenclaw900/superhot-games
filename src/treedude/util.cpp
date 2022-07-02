#include <random>

short getRand(short max)
{
    static std::random_device seed;
    static std::default_random_engine rand{seed()};
    std::uniform_int_distribution<short> dist{0, max};
    return dist(rand);
}