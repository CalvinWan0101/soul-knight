#include "stdafx.h"
#include "event.h"

template <typename R, typename... P>
void Event<R, P...>::Notify(P... parameter)
{
    for (auto func : subscriber)
    {
        func(parameter...);
    }
}

template <typename R, typename... P>
void Event<R, P...>::Subscribe(std::function<R(P... parameter)> func)
{
    subscriber.emplace_back(func);
}

template <typename R, typename... P>
void Event<R, P...>::UnSubscribe(std::function<R(P... parameter)> func)
{
    for (auto it = subscriber.begin(); it != subscriber.end(); ++it) {
        if (it->target_type() == func.target_type()) {
            subscriber.erase(it);
            break; // 找到一個匹配的函數並刪除後就結束循環
        }
    }
}