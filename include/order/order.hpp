#pragma once
#include "menu/pizza.hpp"
#include <map>
#include <vector>

enum OrderStatus
{
    PENDING,
    IN_PROGRESS,
    DELIVERED
};

class Order
{
public:
    Order(std::vector<std::pair<Pizza, int>> pizzas);
    OrderStatus GetStatus();
    void SetStatus(OrderStatus status);
    std::map<Pizza, int> GetOrderComponents();
    int GetPizzaCount();
    int GetOrderId() const;
    double GetTotalPrice() const;
    bool operator<(const Order &other) const;

private:
    static int _next_id;
    std::map<Pizza, int> _pizzas;
    OrderStatus _status;
    int _order_id;
    double _total_price;
};