#include "delivery/delivery_route.hpp"

DeliveryRoute::DeliveryRoute() : _distance_km(0), _estimated_minutes(0), _optimized(false)
{
}

void DeliveryRoute::AddStop(std::shared_ptr<DeliveryAddress> address)
{
    _stops.push_back(address);
    _distance_km += 2.0;
    _estimated_minutes += 5;
}

int DeliveryRoute::GetStopCount() const { return _stops.size(); }
double DeliveryRoute::CalculateDistance() const { return _distance_km; }
int DeliveryRoute::GetEstimatedMinutes() const { return _estimated_minutes; }

void DeliveryRoute::Optimize()
{
    _distance_km *= 0.75;
    _estimated_minutes = (int)(_estimated_minutes * 0.75);
    _optimized = true;
}

bool DeliveryRoute::IsOptimized() const { return _optimized; }