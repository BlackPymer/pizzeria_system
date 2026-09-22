#pragma once
#include "delivery/delivery_address.hpp"
#include <memory>
#include <vector>

class DeliveryRoute
{
public:
    DeliveryRoute();
    void AddStop(std::shared_ptr<DeliveryAddress> address);
    int GetStopCount() const;
    double CalculateDistance() const;
    void Optimize();
    bool IsOptimized() const;
    int GetEstimatedMinutes() const;

private:
    std::vector<std::shared_ptr<DeliveryAddress>> _stops;
    double _distance_km;
    int _estimated_minutes;
    bool _optimized;
};