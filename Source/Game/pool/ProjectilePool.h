#pragma once
#include <vector>

enum class ProjectileType;
class Projectile;

class ProjectilePool {
public:
    static ProjectilePool* Instance();
    ProjectilePool();
    ~ProjectilePool();
    Projectile* Acquire(ProjectileType type);
    void Release(Projectile* projectile);

private:
    void Refresh(Projectile* projectile);
    static ProjectilePool* instance;
    std::vector<std::vector<Projectile*>> pool;
};