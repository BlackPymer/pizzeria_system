#include "human/human.hpp"

int Human::GetAge() const
{
    return _age;
}
std::string Human::GetName() const
{
    return _name;
}
std::string Human::GetPhoneNumber() const
{
    return _phone_number;
}
void Human::SetPhoneNumber(std::string phone_number)
{
    _phone_number = phone_number;
}
Human::Human(int age, std::string name, std::string phone_number)
{
    _age = age;
    _name = name;
    _phone_number = phone_number;
}