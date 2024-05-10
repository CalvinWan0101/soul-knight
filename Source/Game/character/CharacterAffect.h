#pragma once
#include "../utils/object/GeneralObject.h"

class CharacterAffect : public GeneralObject {
public:
    void Start() override;
    void Update() override;
    
    void SetAnimationIndex(int index);
};
