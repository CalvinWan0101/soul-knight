#pragma once
#include "../../Monster.h"
#include "../../../ui/Bar.h"

class ZulanTheColossus : public Monster {
public:
    ZulanTheColossus();
    void Start() override;
    void Update() override;
    void Show(Point screenPositoin) override;
    void OnDead() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;
private:
    bool isAngry;
    bool CheckAngry();
    void CheckState() override;
    Bar hpBar;
};
