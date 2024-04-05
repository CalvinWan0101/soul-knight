#include "stdafx.h"

#include <ddraw.h> //necessary include
#include "../Library/gameutil.h" //necessary include
#include "../Library/gamecore.h" //necessary include
#include "draw.h"

#include "draw_command.h"
#include "draw_empty_rectangle_command.h"
#include "draw_rectangle_command.h"


namespace game_framework {
    Draw* Draw::instance = nullptr;
    
    Draw* Draw::Instance() {
        if (instance == nullptr) {
            instance = new Draw();
        }
        return instance;
    }

    
    void Draw::Rectangle(Point point1, Point point2, COLORREF color, Point radius) {
        CDC *cdc = CDDraw::GetBackCDC(); // get CDC
        DrawCommand* command = new DrawRectangleCommand(point1, point2, color, radius);
        command->Execute(cdc);
        delete command;
        CDDraw::ReleaseBackCDC();
    }
    
    void Draw::EmptyRectangle(Point point1, Point point2, COLORREF color, Point radius, int thickness) {
        CDC *cdc = CDDraw::GetBackCDC(); // get CDC
        DrawCommand* command = new DrawEmptyRectangleCommand(point1, point2, color, radius, thickness);
        command->Execute(cdc);
        delete command;
        CDDraw::ReleaseBackCDC();
    }

}

