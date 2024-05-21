#pragma once
#include "../utils/Interactable.h"
#include "../utils/object/OnceAnimationObject.h"

class Box : public OnceAnimationObject, public Interactable{
public:
    enum Type {
        NORMAL_ROOM,
        BOX_ROOM,
        BOSS_ROOM
    };
    Box(Type type);
    void Start() override;
    void Update() override;
    void LoadResources() override;

    void Interactive(Player* player) override;

private:
    Type type;
    bool isCreateContents;
    void CreateContents();
    void CreateContentsNormalRoom();
    void CreateContentsBoxRoom();
    void CreateContentsBossRoom();
    void CreatePotion();
    void CreateWeapon();
};
