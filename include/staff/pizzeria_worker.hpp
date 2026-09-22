#pragma once
#include "human/human.hpp"
#include <memory>

class PizzaDepartment;

class PizzeriaWorker : virtual public Human
{
public:
    PizzeriaWorker(int age, std::string name, double hourly_rate = 0.0);
    void SetDepartment(std::shared_ptr<PizzaDepartment> department);
    double GetHourlyRate() const;
    void SetHourlyRate(double rate);
    class DepartmentNotSetException : public std::exception
    {
    };

protected:
    std::shared_ptr<PizzaDepartment> _department;
    double _hourly_rate;
};