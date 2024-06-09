#include "stdafx.h"
#include "DevilsSnareSkill2.h"

#include "../../../../../projectile/bullet/RedRectangleBullet.h"

DevilsSnareSkill2::DevilsSnareSkill2(Point* position) : DevilsSnareSkill(position, 5, 5) {
}

void DevilsSnareSkill2::GenerageBullet() {
    Vec rotation{1.0, 1.0};
    for (int i = 0; i < 18; ++i) {
        Bullet* bullet = static_cast<RedRectangleBullet*>(projectilePool->
            Acquire(ProjectileType::RED_RECTANGLE_BULLET));
        bullet->SetSpeed(rotation, 5);
        bullet->SetPosition(&(*(this->position) + Vec(&rotation, 7)));
        bullet->SetDamage(3);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        bullet->SetPoison(true);
        objectManager->AddObject(bullet);
        rotation.Rotate(-0.35);
    }
}
