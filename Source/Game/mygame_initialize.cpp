#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>

#include "config.h"
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;
/////////////////////////////////////////////////////////////////////////////
// ?o??class???C?????C???}?Y?e??????
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame* g) : CGameState(g), page(0) {
}

void CGameStateInit::OnInit() {
    //
    // ????h??AOnInit???J???????n???h????C????K???C?????H
    //     ???????@??A?C???|?X?{?uLoading ...?v?A???Loading???i??C
    //
    ShowInitProgress(0, "Start Initialize..."); // ?@?}?l??loading?i???0%
    //
    // ?}?l???J???
    //
    // Sleep(1000);				// ??C?A?H?K??M???i??A???C????R????Sleep
    //
    // ??OnInit??@?|????CGameStaterRun::OnInit()?A??H?i????S??100%
    //
    // ShowInitProgress(66, "Initialize...");
    // CAudio::Instance()->Load(0, "Resources/sound/background.mp3");
    characterFrames.LoadBitmapByString({
        "Source/Game/ui/character_frame/knight_frame.bmp",
            "Source/Game/ui/character_frame/alchemist_frame.bmp",
            "Source/Game/ui/character_frame/priestess_frame.bmp"
        }, RGB(255,255,255));
    LoadBackground();
    // CAudio::Instance()->Play(0);
}

void CGameStateInit::OnBeginState() {
}

void CGameStateInit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    if (nChar == VK_RETURN)
    {
        page++;
    }
    if (page == 1)
    {
        if (nChar == 'A' && static_cast<int>(ObjectManager::Instance()->GetPlayerType()) != 0)
        {
            ObjectManager::Instance()->SetPlayerType(static_cast<PlayerType>(static_cast<int>(ObjectManager::Instance()->GetPlayerType()) - 1));
        }
        else if (nChar == 'D' && static_cast<int>(ObjectManager::Instance()->GetPlayerType()) != 2)
        {
            ObjectManager::Instance()->SetPlayerType(static_cast<PlayerType>(static_cast<int>(ObjectManager::Instance()->GetPlayerType()) + 1));
        }
    }
}


void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) {
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point) {
    // GotoGameState(GAME_STATE_RUN); // ??????GAME_STATE_RUN
}

void CGameStateInit::OnShow() {
    if (page == 0)
    {
        background.ShowBitmap();
        DrawText();
    }
    else if (page == 1)
    {
        characterFrames.SetFrameIndexOfBitmap(static_cast<int>(ObjectManager::Instance()->GetPlayerType()));
        characterFrames.SetTopLeft(SIZE_X / 2 - characterFrames.GetWidth() / 2, SIZE_Y / 2 - characterFrames.GetHeight() / 2);
        characterFrames.ShowBitmap();
        CDC* pDC = CDDraw::GetBackCDC();

        CTextDraw::ChangeFontLog(pDC, 24, "Consolas", RGB(255, 255, 255));
        CTextDraw::Print(pDC, 280, 800, "Press \"A\", \"D\" to change character.");
        CTextDraw::Print(pDC, 280, 830, "Press \"Enter\" to confirm.");

        CDDraw::ReleaseBackCDC();
    }
    else if (page == 2)
    {
        GotoGameState(GAME_STATE_RUN);
    }
}

void CGameStateInit::LoadBackground() {
    background.LoadBitmapByString({"Resources/Start/first_page.bmp"});
    background.SetTopLeft(0, 0);
}

void CGameStateInit::DrawText() {
    CDC* pDC = CDDraw::GetBackCDC();

    CTextDraw::ChangeFontLog(pDC, 32, "Consolas", RGB(255, 255, 255));
    CTextDraw::Print(pDC, 100, 600, "Press \"Enter\" to start the game....");

    CDDraw::ReleaseBackCDC();
}
