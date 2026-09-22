#pragma once
#include "payment/payment.hpp"
#include <string>

class MobilePayment : public Payment
{
public:
    MobilePayment(double amount, std::string phone, std::string token, std::string provider = "mobile_wallet");
    bool ValidateToken() const;
    bool Process() override;
    std::string GetPhone() const;
    std::string GetProvider() const;

private:
    std::string _phone;
    std::string _token;
    std::string _provider;
};