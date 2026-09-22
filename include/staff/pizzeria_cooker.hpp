#pragma once
#include "staff/pizzeria_worker.hpp"
#include "order/order.hpp"
#include <functional>

class PizzeriaCooker : virtual public PizzeriaWorker
{
public:
    PizzeriaCooker(int age, std::string name, std::string specialty = "pizza_maker");
    virtual void CookOrder(Order order, std::function<void(Order)> onOrderCooked);
    int GetOrdersCooked() const;
    bool IsBusy() const;
    std::string GetSpecialty() const;
    void SetSpecialty(std::string specialty);

protected:
    int _orders_cooked;
    bool _is_busy;
    std::string _specialty;
};