#include "stdafx.h"
#include "MonsterPool.h"

#include "../character/Monster.h"
#include "../character/MonsterFactory.h"

#define PREALLOCATIONS 20

MonsterPool* MonsterPool::instance = nullptr;

MonsterPool* MonsterPool::Instance() {
    if (instance == nullptr) {
        instance = new MonsterPool();
    }
    return instance;
}

MonsterPool::MonsterPool() {
    pool = std::vector<std::vector<Monster*>>(static_cast<int>(MonsterType::COUNT));
    for (int i = 0; i < static_cast<int>(MonsterType::COUNT); i++) {
        std::vector<Monster*> monsters;
        for (int j = 0; j < PREALLOCATIONS; j++) {
            monsters.push_back(MonsterFactory::Create(static_cast<MonsterType>(i)));
        }
        pool.push_back(monsters);
    }
}

MonsterPool::~MonsterPool() {
    for (auto& vector : pool) {
        for (auto monster : vector) {
            delete monster;
        }
        vector.clear();
    }
    pool.clear();
}

Monster* MonsterPool::Acquire(MonsterType type, double level) {
    int index = static_cast<int>(type);
    if (pool[index].empty()) {
        pool[index].push_back(MonsterFactory::Create(type));
    }
    Monster* monster = pool[index].back();
    monster->SetLevel(level);
    monster->Reset();
    pool[index].pop_back();
    return monster;
}

void MonsterPool::Release(Monster* monster) {
    monster->RemoveTag(Tag::DEAD);
    pool[static_cast<int>(monster->GetMonsterType())].push_back(monster);
}
