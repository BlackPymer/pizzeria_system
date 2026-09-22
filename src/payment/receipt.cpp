#include "payment/receipt.hpp"

Receipt::Receipt(int number) : _number(number), _total(0), _discount(0), _payment_method("cash")
{
}

void Receipt::AddLine(std::shared_ptr<MenuItem> item, int count)
{
    _lines[item] += count;
    _total += item->GetTotalPrice() * count;
}

void Receipt::SetTotal(double total) { _total = total; }
double Receipt::GetTotal() const { return _total; }
int Receipt::GetNumber() const { return _number; }
int Receipt::GetLineCount() const { return _lines.size(); }
std::string Receipt::GetPaymentMethod() const { return _payment_method; }
void Receipt::SetPaymentMethod(std::string method) { _payment_method = method; }

std::string Receipt::Print() const
{
    return "Receipt #" + std::to_string(_number) + ": " + std::to_string((int)_total) + " rub";
}