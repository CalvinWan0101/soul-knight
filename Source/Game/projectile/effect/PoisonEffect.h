#pragma once
#include "../../utils/object/InvisibleObject.h"

class PoisonEffect : public InvisibleObject {
public:
    enum Type {
        PLAYER = 5,
        MONSTER_GREEN = 1,
        MONSTER_PURPLE = 2
    };
    PoisonEffect(Type author);
    ~PoisonEffect() override = default;
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;
    void Collision(GameObject* gameObject) override;
private:
    int size;
    const int maxSize = 50;
    int aliveTime;
    int maxAliveTime;
    Type type;
};
