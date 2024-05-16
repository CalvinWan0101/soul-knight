#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <ostream>
#include <iostream>

#include "config.h"
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "character/player/Knight.h"
#include "utils/draw/Draw.h"
#include "stage/TransferGate.h"
#include "wall\Wall.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame* g) : CGameState(g) {
}

CGameStateRun::~CGameStateRun() {
    delete objectManager;
    delete stageManager;
    delete projectilePool;
    delete monsterPool;
    delete Draw::Instance();
}

void CGameStateRun::OnBeginState() {
}

void CGameStateRun::OnMove() // 移動遊戲元素
{
    stageManager->Update();
    objectManager->Update();
}

void CGameStateRun::OnInit() // 遊戲的初值及圖形設定
{
    objectManager->SetPlayer(new Knight());
    objectManager->Start();
    stageManager->Initiliaze();
    CAudio::Instance()->Load(1, "Resources/sound/bullet.mp3");
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
    // TODO: Fixed pressing more than one key
    objectManager->KeyDown(nChar);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) {
    objectManager->KeyUp(nChar);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point) // ?B?z·?????°?§@
{
    objectManager->SetLButtonPress(true);
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point) // ?B?z·?????°?§@
{
    objectManager->SetLButtonPress(false);
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point) // ?B?z·?????°?§@
{
    objectManager->SetPlayerVision(Point(point.x, point.y) - Point(SIZE_X / 2, SIZE_Y / 2));
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point) // ?B?z·?????°?§@
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point) // ?B?z·?????°?§@
{
}

void CGameStateRun::OnShow() {
    objectManager->Show();
    playerState.Show();
}
