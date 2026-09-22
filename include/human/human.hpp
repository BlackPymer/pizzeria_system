#pragma once
#include <string>
class Human
{
public:
    Human(int age, std::string name, std::string phone_number = "");
    int GetAge() const;
    std::string GetName() const;
    std::string GetPhoneNumber() const;
    void SetPhoneNumber(std::string phone_number);

private:
    int _age;
    std::string _name;
    std::string _phone_number;
};