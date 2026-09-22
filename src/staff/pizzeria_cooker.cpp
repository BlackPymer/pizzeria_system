#include "staff/pizzeria_cooker.hpp"
#include "pizzeria/pizzeria_department.hpp"
#include <chrono>
#include <thread>
PizzeriaCooker::PizzeriaCooker(int age, std::string name, std::string specialty)
    : PizzeriaWorker(age, name), Human(age, name), _orders_cooked(0), _is_busy(false), _specialty(specialty)
{
}

void PizzeriaCooker::CookOrder(Order order, std::function<void(Order)> onOrderCooked)
{
    auto dept = _department;
    _is_busy = true;
    std::thread([this, dept, order, onOrderCooked]() mutable
                {
            std::this_thread::sleep_for(std::chrono::seconds(order.GetPizzaCount()));
    onOrderCooked(order);
    _orders_cooked++;
    _is_busy = false;
    dept->CookingFinished(*this); })
        .detach();
}

int PizzeriaCooker::GetOrdersCooked() const
{
    return _orders_cooked;
}

bool PizzeriaCooker::IsBusy() const
{
    return _is_busy;
}

std::string PizzeriaCooker::GetSpecialty() const
{
    return _specialty;
}

void PizzeriaCooker::SetSpecialty(std::string specialty)
{
    _specialty = specialty;
}
