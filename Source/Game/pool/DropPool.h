#pragma once
#include <vector>

enum class DropType;
class Drop;

class DropPool {
public:
    static DropPool* Instance();
    DropPool();
    ~DropPool();
    void Initialize();
    Drop* Acquire(DropType type);
    void Release(Drop* drop);

private:
    static DropPool* instance;
    std::vector<std::vector<Drop*>> pool;
};
