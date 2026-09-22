#include "staff/pizzeria_worker.hpp"
#include "pizzeria/pizzeria_department.hpp"

PizzeriaWorker::PizzeriaWorker(int age, std::string name, double hourly_rate)
    : Human(age, name), _hourly_rate(hourly_rate)
{
}

void PizzeriaWorker::SetDepartment(std::shared_ptr<PizzaDepartment> department)
{
    _department = department;
}

double PizzeriaWorker::GetHourlyRate() const
{
    return _hourly_rate;
}

void PizzeriaWorker::SetHourlyRate(double rate)
{
    _hourly_rate = rate;
}