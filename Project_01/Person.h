#include <iostream>
#include <array>
#include <string>

#ifndef Person_h
#define Person_h

class Person
{
std::string name;
uint8_t age;

public:
Person(std::string name, uint8_t age);

//setters and getters
void set_Age(uint8_t age);
uint8_t get_Age() const;

void set_Name(std::string name);
std::string get_Name() const;
};

#endif //Person_h