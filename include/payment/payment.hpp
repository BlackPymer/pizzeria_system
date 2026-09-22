#pragma once
#include <string>

enum PaymentStatus
{
    PAYMENT_PENDING,
    PAYMENT_PAID,
    PAYMENT_DECLINED,
    PAYMENT_REFUNDED
};

class Payment
{
public:
    Payment(double amount, std::string payment_method = "unknown");
    virtual ~Payment() = default;
    virtual bool Process() = 0;
    virtual bool Refund();
    virtual double GetChange() const;
    double GetAmount() const;
    PaymentStatus GetStatus() const;
    std::string GetPaymentMethod() const;
    void SetPaymentMethod(std::string method);

protected:
    PaymentStatus _status;

private:
    double _amount;
    std::string _payment_method;
};