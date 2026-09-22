#include "staff/accountant.hpp"

Accountant::Accountant(int age, std::string name)
    : PizzeriaWorker(age, name), Human(age, name), _total_revenue(0), _total_expenses(0), _total_payroll(0), _transactions_count(0)
{
}

void Accountant::RecordRevenue(double amount) { _total_revenue += amount; _transactions_count++; }
void Accountant::RecordExpense(double amount) { _total_expenses += amount; _transactions_count++; }
void Accountant::RecordPayroll(double amount) { _total_payroll += amount; _transactions_count++; }
double Accountant::GetTotalRevenue() const { return _total_revenue; }
double Accountant::GetTotalExpenses() const { return _total_expenses + _total_payroll; }
double Accountant::GetNetProfit() const { return _total_revenue - GetTotalExpenses(); }
int Accountant::GetTransactionsCount() const { return _transactions_count; }
double Accountant::CalculateSalary(double hourly_rate, int hours) const { return hourly_rate * hours; }