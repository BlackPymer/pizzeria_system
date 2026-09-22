#include "order/order.hpp"

int Order::_next_id = 0;

Order::Order(std::vector<std::pair<Pizza, int>> pizzas) : _total_price(0)
{
    for (const std::pair<Pizza, int> &a : pizzas)
    {
        _pizzas[a.first] = a.second;
        _total_price += a.first.GetTotalPrice() * a.second;
    }
    _status = PENDING;
    _order_id = ++_next_id;
}
OrderStatus Order::GetStatus() { return _status; }
void Order::SetStatus(OrderStatus status) { _status = status; }
std::map<Pizza, int> Order::GetOrderComponents() { return _pizzas; }
int Order::GetPizzaCount() { return _pizzas.size(); }
int Order::GetOrderId() const { return _order_id; }
double Order::GetTotalPrice() const { return _total_price; }
bool Order::operator<(const Order &order) const
{
    if (_pizzas.size() != order._pizzas.size())
        return _pizzas.size() < order._pizzas.size();
    return _pizzas < order._pizzas;
}