#pragma once
#include <vector>

enum class MonsterType;
class Monster;

class MonsterPool {
public:
    static MonsterPool* Instance();
    MonsterPool();
    ~MonsterPool();
    void Initialize();
    Monster* Acquire(MonsterType type, double level = 1);
    void Release(Monster* monster);

private:
    static MonsterPool* instance;
    std::vector<std::vector<Monster*>> pool;
};
