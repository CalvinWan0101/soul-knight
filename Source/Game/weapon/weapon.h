#pragma once
#include "../utils/game_object.h"

class Weapon : public game_framework::GameObject 
{
public:
    Weapon();
    void Start() override = 0;
    void Update() override = 0;
    virtual void Attack() = 0;
    int GetCd();
    int GetDamage();
    int GetMpCost();
    
private:
    int cd;
    int damage;
    int mpCost;
    
    
};
