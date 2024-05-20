#include "stdafx.h"
#include "Rand.h"

Rand* Rand::instance = nullptr;

Rand* Rand::Instance() {
    if (!instance) {
        instance = new Rand();
    }
    return instance;
}

Rand::Rand() {
    std::random_device rd;
    rng.seed(rd());
}

Rand::~Rand() {
}

int Rand::Get(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

