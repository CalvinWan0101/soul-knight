/*
 * mygame.h: ¢FFFFFFFD???????x?C??¢FFFFFFFD?????class??interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

#include "manager/ObjectManager.h"
#include "manager/StageManager.h"
#include "manager/UIManager.h"
#include "pool/DropPool.h"
#include "pool/MonsterPool.h"
#include "pool/ProjectilePool.h"
#include "ui/PlayerState.h"

namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // Constants
    /////////////////////////////////////////////////////////////////////////////

    enum AUDIO_ID {
        // ?w?q?U?????????s??
        AUDIO_DING,
        // 0
        AUDIO_LAKE,
        // 1
        AUDIO_NTUT // 2
    };

    /////////////////////////////////////////////////////////////////////////////
    // ?o??class?¢FFFFFFFX?C?????C???}?Y?e?????¢FFFFFFFD?
    // ?C??Member function??Implementation?¢FFFFFFFG?n??????
    /////////////////////////////////////////////////////////////////////////////

    class CGameStateInit : public CGameState {
    public:
        CGameStateInit(CGame* g);
        void OnInit(); // ?C?????????????????]?w
        void OnBeginState(); // ?]?w?C?????????????????
        void OnKeyUp(UINT, UINT, UINT); // ?B?z???LUp??¢FFFFFFFX????@
        void OnLButtonDown(UINT nFlags, CPoint point); // ?B?z?P?????¢FFFFFFFX????@
    protected:
        void OnShow(); // ??¢FFFFFFFD??o?????A???C???e???
    private:
        void LoadBackground();
        void DrawText();
        CMovingBitmap background; // csie??logo
    };

    /////////////////////////////////////////////////////////////////////////////
    // ?o??class?¢FFFFFFFX?C?????C??¢FFFFFFFX?????¢FFFFFFFD??A¢FFFFFFFDD?n???C???{???¢FFFFFFFG?b?o??
    // ?C??Member function??Implementation?¢FFFFFFFG?n??????
    /////////////////////////////////////////////////////////////////////////////

    class CGameStateRun : public CGameState {
    public:
        CGameStateRun(CGame* g);
        ~CGameStateRun();
        void OnBeginState(); // ?]?w?C?????????????????
        void OnInit(); // ?C?????????????????]?w
        void OnKeyDown(UINT, UINT, UINT);
        void OnKeyUp(UINT, UINT, UINT);
        void OnLButtonDown(UINT nFlags, CPoint point); // ?B?z?P?????¢FFFFFFFX????@
        void OnLButtonUp(UINT nFlags, CPoint point); // ?B?z?P?????¢FFFFFFFX????@
        void OnMouseMove(UINT nFlags, CPoint point); // ?B?z?P?????¢FFFFFFFX????@ 
        void OnRButtonDown(UINT nFlags, CPoint point); // ?B?z?P?????¢FFFFFFFX????@
        void OnRButtonUp(UINT nFlags, CPoint point); // ?B?z?P?????¢FFFFFFFX????@
    protected:
        void OnMove(); // ??¢FFFFFFFX??C??????
        void OnShow(); // ??¢FFFFFFFD??o?????A???C???e???
        ObjectManager* objectManager = ObjectManager::Instance();
        StageManager* stageManager = StageManager::Instance();
        ProjectilePool* projectilePool = ProjectilePool::Instance();
        MonsterPool* monsterPool = MonsterPool::Instance();
        DropPool* dropPoll = DropPool::Instance(); 
        UIManager uiManager;
    };

    /////////////////////////////////////////////////////////////////////////////
    // ?o??class?¢FFFFFFFX?C?????????????A(Game Over)
    // ?C??Member function??Implementation?¢FFFFFFFG?n??????
    /////////////////////////////////////////////////////////////////////////////

    class CGameStateOver : public CGameState {
    public:
        CGameStateOver(CGame* g);
        void OnBeginState(); // ?]?w?C?????????????????
        void OnInit();

    protected:
        void OnMove(); // ??¢FFFFFFFX??C??????
        void OnShow(); // ??¢FFFFFFFD??o?????A???C???e???
    private:
        int counter; // ?????????p????
    };
}
