#include "stdafx.h"
#include "gun.h"

Gun::Gun()
{
    rotation = Vec(1, 0);
}

void Gun::SetRotation(Vec* radian)
{
    rotation = Vec(radian);
}

Vec Gun::GetRotation() const
{
    return rotation;
}
