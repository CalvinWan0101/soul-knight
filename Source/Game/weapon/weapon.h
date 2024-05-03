#pragma once
#include "../utils/object/RotatableObject.h"

class Weapon : public RotatableObject {
public:
    Weapon();
    Weapon(Point point);
    virtual Weapon* Copy() = 0;
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
    int cd; // frame
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
