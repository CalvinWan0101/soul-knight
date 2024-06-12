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
// ?o??class???C???????????A(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::Result CGameStateOver::result = FAILED;

CGameStateOver::CGameStateOver(CGame* g): CGameState(g) {
}

void CGameStateOver::OnMove() {
    // GotoGameState(GAME_STATE_INIT);
}

void CGameStateOver::OnBeginState() {
}

void CGameStateOver::OnInit() {
    // //
    // // ????h??AOnInit???J???????n???h????C????K???C?????H
    // //     ???????@??A?C???|?X?{?uLoading ...?v?A???Loading???i??C
    // //
    // ShowInitProgress(66, "Initialize..."); // ????e?@????A???i??A???B?i?????66%
    // //
    // // ?}?l???J???
    // //
    // Sleep(1000); // ??C?A?H?K??M???i??A???C????R????Sleep
    // //
    // // ???i???100%
    // //
    // ShowInitProgress(100, "OK!");
    //
    // Sleep(1000);
}

void CGameStateOver::OnShow() {
    CDC* pDC = CDDraw::GetBackCDC();
    if (CGameStateOver::result == FAILED) {
        CTextDraw::ChangeFontLog(pDC, 80, "Consolas", RGB(255, 50, 50));
        CTextDraw::Print(pDC, SIZE_X / 2 - 200, 200, "YOU DEAD");
    }
    else if (CGameStateOver::result == SUCCESS) {
        CTextDraw::ChangeFontLog(pDC, 80, "Consolas", RGB(249,222,89));
        CTextDraw::Print(pDC, SIZE_X / 2 - 200, 200, "YOU WIN!");
    }
    CDDraw::ReleaseBackCDC();
}
