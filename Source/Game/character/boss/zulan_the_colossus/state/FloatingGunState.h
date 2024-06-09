#pragma once

class FloatingGun;

class FloatingGunState
{
public:
    FloatingGunState(FloatingGun* floatingGun);
    virtual ~FloatingGunState() = default;
    virtual void Update() = 0;
protected:
    FloatingGun* floatingGun;
};
