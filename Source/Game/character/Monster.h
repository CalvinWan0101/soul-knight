#pragma once
#include "Character.h"
#include "DamageText.h"
#include "MonsterType.h"
#include "../utils/PlayerAlertable.h"

class Player;

class Monster : public Character, public PlayerAlertable{
public:
    Monster(double level);
    void Start() override;
    void Update() override;
    void OnRemove() override;
    virtual void OnDead();
    void Collision(GameObject* gameObject) override;
    virtual void AutoMationMove();
    virtual void AutoMation() = 0;
    virtual void InitializeWeapon() = 0;
    void EnterPlayerAlertRange(Player* player) override;

    void SetWeapon(Weapon* weapon);
    void SetLevel(double level);
    void Reset();
    MonsterType GetMonsterType();
    void Injuried(double damage) override;

protected:
    double maxSpeed;
    double level;
    int monsterType;
    void SetMonsterType(MonsterType type);

private:
    bool isInitializeWeapon;
    bool isOnDeadTrigger;
    Player* player = nullptr;
    void CreateNewDamageText();
    DamageText* damageText;
};
