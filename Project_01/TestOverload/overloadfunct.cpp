#include "overLoadFunct.h"


uint8_t overLoadFunct::getvalueToPrint() const
{
    return valueToPrint;
}

void overLoadFunct::setValueToPrint(uint8_t valueToPrint)
{
	this->valueToPrint = valueToPrint;
}

std::ostream &operator<<(std::ostream &os, overLoadFunct &test)
{
	os << test.getvalueToPrint();
	return os;
}