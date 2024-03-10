#include "stdafx.h"
#include "character.h"

Character::Character()
{

}

void Character::Start()
{
    
}

void Character::Update()
{
    CheckState();
    if (state <= 1)
    {
        index = state + 2 * face;
    }
}

int Character::GetHP()
{
    return hp;
}

int Character::GetMaxHP()
{
    return maxHp;
}

void Character::CheckState()
{
    if (speed.GetX() > 0)
    {
        face = RIGHT;
    }
    else if (speed.GetX() < 0)
    {
        face = LEFT;
    }

    if (speed.GetLength() == 0.0)
    {
        state = IDLE;
    }
    else if (speed.GetLength() != 0.0)
    {
        state = RUN;
    }
    if (hp == 0)
    {
        state = DEAD;
    }
}




