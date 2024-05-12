#include "stdafx.h"
#include "ProjectilePool.h"

#include "../projectile/Projectile.h"
#include "../projectile/ProjectileFactory.h"

#define PREALLOCATIONS 50

class Arrow;
ProjectilePool* ProjectilePool::instance = nullptr;

ProjectilePool* ProjectilePool::Instance() {
    if (instance == nullptr) {
        instance = new ProjectilePool();
    }
    return instance;
}

ProjectilePool::ProjectilePool() {
    pool = std::vector<std::vector<Projectile*>>(static_cast<int>(ProjectileType::COUNT));
    for (int i = 0; i < static_cast<int>(ProjectileType::COUNT); i++) {
        std::vector<Projectile*> projectiles;
        for (int j = 0; j < PREALLOCATIONS; j++) {
            projectiles.push_back(ProjectileFactory::Create(static_cast<ProjectileType>(i)));
        }
        pool.push_back(projectiles);
    }
}

ProjectilePool::~ProjectilePool() {
    for (auto& vector : pool) {
        for (auto projectile : vector) {
            delete projectile;
        }
        vector.clear();
    }
    pool.clear();
}


Projectile* ProjectilePool::Acquire(ProjectileType type) {
    int index = static_cast<int>(type);
    if (pool[index].empty()) {
        pool[index].push_back(ProjectileFactory::Create(type));
    }
    Projectile* projectile = pool[index].back();
    pool[index].pop_back();
    return projectile;
}

void ProjectilePool::Release(Projectile* projectile) {
    pool[static_cast<int>(projectile->GetProjectileType())].push_back(projectile);
}
