#include "stdafx.h"

#include <ddraw.h> //necessary include
#include "../Library/gameutil.h" //necessary include
#include "../Library/gamecore.h" //necessary include
#include "draw.h"

#include "draw_command.h"
#include "draw_empty_rectangle_command.h"
#include "draw_rectangle_command.h"
#include "draw_text_command.h"


namespace game_framework {
    Draw* Draw::instance = nullptr;
    
    Draw* Draw::Instance() {
        if (instance == nullptr) {
            instance = new Draw();
        }
        return instance;
    }

    
    void Draw::Rectangle(Point point1, Point point2, COLORREF color, Point radius) {
        this->drawCommands.emplace_back(new DrawRectangleCommand(point1, point2, color, radius));
    }
    
    void Draw::EmptyRectangle(Point point1, Point point2, COLORREF color, Point radius, int thickness) {
        this->drawCommands.emplace_back(new DrawEmptyRectangleCommand(point1, point2, color, radius, thickness));
    }

    void Draw::Text(Point point, int size, COLORREF color, std::string str, std::string fontName) {
        this->drawCommands.emplace_back((new DrawTextCommand(point, size, color, str, fontName)));
    }

    void Draw::SwitchIsDisplay() {
        isDisplayed = !isDisplayed; 
    }
    
    void Draw::Show() {
        CDC *cdc = CDDraw::GetBackCDC(); // get CDC
        for(int i = static_cast<int>(drawCommands.size()) - 1 ; i >= 0 ; i--) {
            if (isDisplayed) {
                drawCommands[i]->Execute(cdc);
            }
            delete drawCommands[i];
            drawCommands.pop_back();
        }
        CDDraw::ReleaseBackCDC();
    }


}

