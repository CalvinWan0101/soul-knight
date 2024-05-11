#pragma once
#include "../utils/object/RotatableObject.h"

class Weapon : public RotatableObject {
public:
    Weapon();
    Weapon(Point point);
    Weapon(int damage);
    virtual Weapon* Copy() = 0;
    void Start() override;
    void Update() override;
    void DefaultAttack();
    virtual void Aim(Vec* direction);
    virtual void Attack() = 0;
    virtual void SetAttackAnimation(vector<double> attackRotationOffsets, vector<double> attackTranslationOffsets ,double second, double attackTiming = 0);
    int GetDamage();
    void SetDamage(int damage);
    int GetMpCost();
    
protected:
    int frameCd; // how many frames to wait for next attack
    int damage;
    int mpCost;
private:
    int cdCounter; // minus 1 per frame
    double attackTiming; // 0 <= attackTiming < 1, percentage of the whole animation 
    bool isAttack;
    double attackFace;
    double attackRotationOffset;
    vector<double> attackRotationOffsets;
    double attackTranslationOffset;
    vector<double> attackTranslationOffsets;
    void UpdateRotationOffset();
    void UpdateTranslationOffset();
    void SetFrameCd(double second);
};
