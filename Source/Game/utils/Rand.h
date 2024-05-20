#pragma once
#include <random>

class Rand {
public:
    static Rand* Instance();
    Rand();
    ~Rand();
    int Get(int min, int max);
private:
    static Rand* instance;
    std::mt19937 rng;
};
