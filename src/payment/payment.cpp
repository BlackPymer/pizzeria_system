#include "payment/payment.hpp"

Payment::Payment(double amount, std::string payment_method)
    : _status(PAYMENT_PENDING), _amount(amount), _payment_method(payment_method)
{
}

bool Payment::Refund()
{
    if (_amount <= 0)
        return false;
    _status = PAYMENT_REFUNDED;
    return true;
}

double Payment::GetChange() const { return 0; }
double Payment::GetAmount() const { return _amount; }
PaymentStatus Payment::GetStatus() const { return _status; }
std::string Payment::GetPaymentMethod() const { return _payment_method; }
void Payment::SetPaymentMethod(std::string method) { _payment_method = method; }