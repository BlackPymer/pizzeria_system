#include "kitchen/supplier.hpp"

Supplier::Supplier(std::string name, int delivery_days, double minimum_order)
    : _name(name), _delivery_days(delivery_days), _delivery_fee(100), _minimum_order(minimum_order)
{
}

void Supplier::SetPriceFor(std::shared_ptr<Ingredient> ingredient, double price)
{
    _price_list[ingredient] = price;
}

double Supplier::GetPriceFor(std::shared_ptr<Ingredient> ingredient) const
{
    auto it = _price_list.find(ingredient);
    if (it == _price_list.end())
        return 0;
    return it->second;
}

double Supplier::PlaceOrder(int units) const
{
    if (units <= 0)
        return 0;
    return _delivery_fee + units * 50;
}

int Supplier::GetDeliveryDays() const { return _delivery_days; }
std::string Supplier::GetName() const { return _name; }
double Supplier::GetMinimumOrder() const { return _minimum_order; }
void Supplier::SetMinimumOrder(double amount) { _minimum_order = amount; }