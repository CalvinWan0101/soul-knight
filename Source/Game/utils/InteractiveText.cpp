#include "stdafx.h"
#include "InteractiveText.h"

#include "draw/Draw.h"

InteractiveText::InteractiveText(std::string displayText, Rarity rarity, int verticalOffset) {
    this->displayText = displayText;
    this->color = rarity;
    this->isInteractive = false;
    this->displayOffset = Point(static_cast<double>(displayText.size()) * -3.75, verticalOffset);
}

void InteractiveText::Show(Point screenPoint) {
    if (isInteractive) {
        isInteractive = false;
        game_framework::Draw::Instance()->Text(screenPoint + this->displayOffset, 12, this->color, this->displayText);   
    }
}

void InteractiveText::Interactive() {
    isInteractive = true;
}