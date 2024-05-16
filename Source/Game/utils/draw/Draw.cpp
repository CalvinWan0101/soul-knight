#include "stdafx.h"

#include <ddraw.h> //necessary include
#include "../Library/gameutil.h" //necessary include
#include "../Library/gamecore.h" //necessary include
#include "Draw.h"

#include "DrawCommand.h"
#include "DrawEmptyRectangleCommand.h"
#include "DrawRectangleCommand.h"
#include "DrawTextCommand.h"


namespace game_framework {
    Draw* Draw::instance = nullptr;
    
    Draw* Draw::Instance() {
        if (instance == nullptr) {
            instance = new Draw();
        }
        return instance;
    }

    Draw::Draw() : isDisplayed(true) {
    }

    Draw::~Draw() {
        for(int i = static_cast<int>(drawCommands.size()) - 1 ; i >= 0 ; i--) {
            delete drawCommands[i];
            drawCommands.pop_back();
        }
    }
    
    void Draw::Rectangle(Point point1, Point point2, COLORREF color, int alpha) {
        this->drawCommands.emplace_back(new DrawRectangleCommand(point1, point2, color, alpha));
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

