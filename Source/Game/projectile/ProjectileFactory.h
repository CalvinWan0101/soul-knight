#pragma once

class Projectile;
enum class ProjectileType;

class ProjectileFactory {
public:
    static Projectile* Create(ProjectileType type);
};
