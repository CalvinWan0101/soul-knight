#pragma once

class DrawCommand {
public:
    virtual void Execute(CDC* cdc) = 0;
    virtual ~DrawCommand(){}
};
