#include "stack.h"
#include <iostream>

int main(int argc, char *argv[])
{
	 //Using argv and argc to push values to the stack
    Stack<std::string> equation(50);

       for (int i = 1; i<argc; i++ )
       {
           equation.push((argv[i]));

       }

       std::cout<< equation.evaluate();

}