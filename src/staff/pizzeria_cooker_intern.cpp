#include "staff/pizzeria_cooker_intern.hpp"
#include <chrono>
#include <thread>
#include "pizzeria/pizzeria_department.hpp"
PizzeriaCookerIntern::PizzeriaCookerIntern(int age, std::string name)
    : PizzeriaCooker(age, name), Intern(), Human(age, name), PizzeriaWorker(age, name), _training_score(0)
{
}

PizzeriaCookerIntern::PizzeriaCookerIntern(int age, std::string name, double time_factor)
    : PizzeriaCooker(age, name), Intern(time_factor), Human(age, name), PizzeriaWorker(age, name), _training_score(0)
{
}
void PizzeriaCookerIntern::CookOrder(Order order, std::function<void(Order)> onOrderCooked)
{
    double time_factor = _time_factor;
    auto dept = _department;
    _is_busy = true;

    std::thread([this, dept, order, onOrderCooked, time_factor]() mutable
                {
    std::this_thread::sleep_for(std::chrono::milliseconds((long)(order.GetPizzaCount()*time_factor*1000)));
    onOrderCooked(order);
    _orders_cooked++;
    _training_score++;
    _is_busy = false;
    dept->CookingFinished(*this); })
        .detach();
}

int PizzeriaCookerIntern::GetTrainingScore() const
{
    return _training_score;
}

void PizzeriaCookerIntern::SetTrainingScore(int score)
{
    _training_score = score;
}