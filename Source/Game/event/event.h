#pragma once
#include <functional>
#include <vector>

template <typename R , typename... P>
class Event
{
public:
    void Notify(P... parameter);
    void Subscribe(std::function<R(P...)> func);
    void UnSubscribe(std::function<R(P...)> func);
private:
    std::vector<std::function<R(P...)>> subscriber;
};

#include "event.cpp"