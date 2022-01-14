#include "Person.h"

Person::Person(std::string name, uint8_t age)
{
    this->age = age;
    this->name = name;
}


uint8_t Person::get_Age() const
{
    return age;
}

void Person::set_Age(uint8_t age)
{
    this->age = age;
}

void Person::set_Name(std::string name)
{
    this->name = name;
}

std::string Person::get_Name() const
{
    return name;
}