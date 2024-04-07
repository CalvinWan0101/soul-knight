#include "stdafx.h"
#include "draw_text_command.h"
#include "../../Library/gameutil.h"

DrawTextCommand::DrawTextCommand(Point point, int size, COLORREF color, std::string str, std::string fontName) {
    this->point = point;
    this->size = size;
    this->color = color;
    this->str = str;
    this->fontName = fontName;
}

DrawTextCommand::~DrawTextCommand() = default;

void DrawTextCommand::Execute(CDC* cdc) {
    game_framework::CTextDraw::ChangeFontLog(cdc, size, fontName, color);
    game_framework::CTextDraw::Print(cdc, static_cast<int>(this->point.GetX()), static_cast<int>(this->point.GetY()), str);
}



