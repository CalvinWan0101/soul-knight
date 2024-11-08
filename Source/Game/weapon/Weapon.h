#pragma once
#include "../projectile/InvisibleShockWave.h"
#include "../projectile/ShockWave.h"
#include "../utils/InteractableDevice.h"
#include "../utils/object/RotatableObject.h"

class Bullet;

class Weapon : public RotatableObject, public InteractableDevice {
public:
    Weapon();
    virtual Weapon* Copy() = 0;
    void Start() override;
    void Update() override;
    void DefaultAttack();
    virtual void Aim(Vec* direction);
    virtual void Attack() = 0;
    void Interactive(Player* player) override;
    virtual void SetAttackAnimation(vector<double> attackRotationOffsets, vector<double> attackTranslationOffsets,
                                    double second, double attackTiming = 0);
    double GetDamage();
    void SetDamage(double damage);
    int GetMpCost();
    bool CanAttack();

protected:
    int frameCd; // how many frames to wait for next attack
    double damage;
    int mpCost;
    void UpdateTag(GameObject* gameObject);

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
