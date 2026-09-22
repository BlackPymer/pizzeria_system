#include "menu/menu_item.hpp"

MenuItem::MenuItem(std::string name, std::string category, double price, int weight, int calories, bool is_available)
    : _name(name), _category(category), _price(price), _weight(weight), _calories(calories), _is_available(is_available)
{
}

std::string MenuItem::GetName() const { return _name; }
std::string MenuItem::GetCategory() const { return _category; }
double MenuItem::GetPrice() const { return _price; }
int MenuItem::GetWeight() const { return _weight; }
int MenuItem::GetCalories() const { return _calories; }
void MenuItem::SetPrice(double price) { _price = price; }
bool MenuItem::IsAvailable() const { return _is_available; }
void MenuItem::SetAvailable(bool available) { _is_available = available; }
double MenuItem::GetTotalPrice() const { return _price; }
int MenuItem::GetTotalCalories() const { return _calories; }