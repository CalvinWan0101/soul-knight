#pragma once
#include <functional>
#include <vector>

template <typename R, typename... P>
class Event
{
public:
    void Notify(P... parameter)
    {
        for (auto func : subscriber)
        {
            func(parameter...);
        }
    }

    void Subscribe(std::function<R(P...)> func)
    {
        subscriber.emplace_back(func);
    }

    void UnSubscribe(std::function<R(P...)> func)
    {
        for (auto it = subscriber.begin(); it != subscriber.end(); ++it)
        {
            if (it->target_type() == func.target_type())
            {
                subscriber.erase(it);
                break;
            }
        }
    }

private:
    std::vector<std::function<R(P...)>> subscriber;
};
