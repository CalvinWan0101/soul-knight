#pragma once
#include "../utils/rotatable_object.h"

class Weapon : public RotatableObject {
public:
    Weapon();
    void Start() override;
    void Update() override;
    void DefaultAttack();
    virtual void Aim(Vec* direction);
    virtual void Attack() = 0;
    virtual void SetAttackAnimation(vector<double> attackRotationOffsetList, double cd, double attackTiming = 0);
    void SetCd(double cd);
    double GetCd();
    int GetDamage();
    int GetMpCost();
    
protected:
    int cd;
    int damage;
    int mpCost;
private:
    int cdCounter;
    double attackTiming; // 0 <= attackTiming < 1
    bool isAttack;
    double attackFace;
    double attackRotationOffset;
    vector<double> attackRotationOffsetList;
    void CalcRotationOffset();

};
