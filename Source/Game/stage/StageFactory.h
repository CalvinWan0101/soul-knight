#pragma once

class Stage;

class StageFactory {
public:
    static Stage* Create(int level, int stage);
};
