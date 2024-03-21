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

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame* g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
    delete player;
    delete monster;
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove() // 移動遊戲元素
{
    monster->DefaultUpdate();
    player->DefaultUpdate();
}

void CGameStateRun::OnInit() // 遊戲的初值及圖形設定
{
    monster->DefaultStart();
    player->DefaultStart();
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    if (nChar == 'A')
    {
        player->GetSpeed().SetX(player->GetSpeed().GetX() - 10);
    }
    if (nChar == 'D')
    {
        player->GetSpeed().SetX(player->GetSpeed().GetX() + 10);
    }
    if (nChar == 'W')
    {
        player->GetSpeed().SetY(player->GetSpeed().GetY() - 10);
    }
    if (nChar == 'S')
    {
        player->GetSpeed().SetY(player->GetSpeed().GetY() + 10);
    }
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    if (nChar == 'A')
    {
        player->GetSpeed().SetX(player->GetSpeed().GetX() + 10);
    }
    if (nChar == 'D')
    {
        player->GetSpeed().SetX(player->GetSpeed().GetX() - 10);
    }
    if (nChar == 'W')
    {
        player->GetSpeed().SetY(player->GetSpeed().GetY() + 10);
    }
    if (nChar == 'S')
    {
        player->GetSpeed().SetY(player->GetSpeed().GetY() - 10);
    }
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point) // 處理滑鼠的動作
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point) // 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point) // 處理滑鼠的動作
{
    player->SetVision(Point(point.x, point.y) - Point(SIZE_X / 2, SIZE_Y / 2));
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point) // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point) // 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
    screenX = (int)player->GetPoint().GetX() - SIZE_X / 2;
    screenY = (int)player->GetPoint().GetY() - SIZE_Y / 2;
    monster->Show(Point(screenX, screenY));
    player->Show(Point(screenX, screenY));
}
