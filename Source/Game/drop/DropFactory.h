#pragma once

enum class DropType;
class Drop;


class DropFactory {
public:
    static Drop* Create(DropType type);
};
