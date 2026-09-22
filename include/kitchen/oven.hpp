#pragma once
#include <functional>

class Oven
{
public:
    Oven(int max_load = 100);
    void Preheat(int target_temperature);
    int GetTemperature() const;
    void SetLoad(int load);
    int GetLoad() const;
    bool IsReady() const;
    int GetMaxLoad() const;
    int GetBakeCount() const;
    void Bake(int seconds, std::function<void()> onDone);

private:
    int _target_temperature;
    int _temperature;
    int _load;
    bool _is_preheated;
    int _max_load;
    int _bake_count;
};