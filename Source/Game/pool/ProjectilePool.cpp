#include "stdafx.h"
#include "ProjectilePool.h"

#include "../projectile/Projectile.h"
#include "../projectile/ProjectileFactory.h"
#include "../utils/object/GameObject.h"

#define PREALLOCATIONS 50

ProjectilePool* ProjectilePool::instance = nullptr;

ProjectilePool* ProjectilePool::Instance() {
    if (instance == nullptr) {
        instance = new ProjectilePool();
    }
    return instance;
}

ProjectilePool::ProjectilePool() {
    pool = std::vector<std::vector<Projectile*>>(static_cast<int>(ProjectileType::COUNT));
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

void ProjectilePool::Initialize() {
    for (int i = 0; i < static_cast<int>(ProjectileType::COUNT); i++) {
        std::vector<Projectile*> projectiles;
        for (int j = 0; j < PREALLOCATIONS; j++) {
            GameObject* gameObject = dynamic_cast<GameObject*>(
                ProjectileFactory::Create(static_cast<ProjectileType>(i)));
            gameObject->Start();
            projectiles.push_back(dynamic_cast<Projectile*>(gameObject));
        }
        pool.push_back(projectiles);
    }
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
    Refresh(projectile);
    pool[static_cast<int>(projectile->GetProjectileType())].push_back(projectile);
}

void ProjectilePool::Refresh(Projectile* projectile) {
    projectile->SetPoison(false);
}
