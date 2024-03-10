#include "stdafx.h"
#include "player.h"

#include "../../config.h"
#include "character.h"

Player::Player()
{
    mp = 0;
    shield = 0;
}

void Player::Start()
{
    
}

void Player::Update()
{
    Character::Update();
}

int Player::GetMP()
{
    return mp;
}

int Player::GetMaxMP()
{
    return  maxMp;
}

int Player::GetShield()
{
    return shield;
}

int Player::GetMaxShield()
{
    return maxShild;
}

