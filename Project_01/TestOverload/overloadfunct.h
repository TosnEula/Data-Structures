#include <iostream>
#include <string>

#ifndef overLoadFunct_h
#define overLoadFunct_h

class overLoadFunct {
    uint8_t valueToPrint;

public:
    uint8_t getvalueToPrint() const;
    void setValueToPrint(uint8_t valueToPrint);

    friend std::ostream &operator<<(std::ostream &os, overLoadFunct &test);

};

#endif //overLoadFunct_h