#pragma once
#include "menu/ingredient.hpp"
#include <map>
#include <memory>
#include <string>

class Supplier
{
public:
    Supplier(std::string name, int delivery_days, double minimum_order = 0);
    void SetPriceFor(std::shared_ptr<Ingredient> ingredient, double price);
    double GetPriceFor(std::shared_ptr<Ingredient> ingredient) const;
    double PlaceOrder(int units) const;
    int GetDeliveryDays() const;
    std::string GetName() const;
    double GetMinimumOrder() const;
    void SetMinimumOrder(double amount);

private:
    std::string _name;
    int _delivery_days;
    double _delivery_fee;
    double _minimum_order;
    std::map<std::shared_ptr<Ingredient>, double> _price_list;
};