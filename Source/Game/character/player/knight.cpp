#include "stdafx.h"
#include "knight.h"

Knight::Knight()
{
    state = IDLE;
}

void Knight::Start()
{
    this->AddAnimation({
                           "resources/player/knight/idle/1.bmp",
                           "resources/player/knight/idle/2.bmp",
                           "resources/player/knight/idle/3.bmp",
                           "resources/player/knight/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/knight/run/1.bmp",
                           "resources/player/knight/run/2.bmp",
                           "resources/player/knight/run/3.bmp",
                           "resources/player/knight/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/knight/idle/flip_1.bmp",
                           "resources/player/knight/idle/flip_2.bmp",
                           "resources/player/knight/idle/flip_3.bmp",
                           "resources/player/knight/idle/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/knight/run/flip_1.bmp",
                           "resources/player/knight/run/flip_2.bmp",
                           "resources/player/knight/run/flip_3.bmp",
                           "resources/player/knight/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void Knight::Update()
{
    Player::Update();
}
