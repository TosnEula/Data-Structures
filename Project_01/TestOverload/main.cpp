#include <iostream>
#include "overloadfunct.h"

int main()
{
    overLoadFunct test1;
    uint8_t x;
    std::cout << "Please enter a 8 bit integer";
	std::cin >> x;

    test1.setValueToPrint(x);

	std::cout << test1;
}
