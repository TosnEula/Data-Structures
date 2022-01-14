#include "stack.h"
#include <iostream>

int main(int argc, char *argv[])
{
    //Showing the functionality of the stack
    Stack<std::string> equation(20);

    //pushing values to the stack
    equation.push("50.1");
    equation.push("30");
    equation.push("+");
    equation.push("2");
    equation.push("/");

    //printing the value at the top of the stack
    std::cout << "top of the stack is: "<< equation.top() << std::endl;

    //printing all the values in the stack.
    equation.printStack();


    //popping the top two values and printing the new top
    equation.pop();
    equation.pop();
    std::cout << "\nAfter removing two values the value at the top of the stack is: "<< equation.top() << std::endl;

    //printing all the values currently in the stack
    equation.printStack();
    std::cout<< std::endl;

    //Using the evaluate function
    std::cout << "The result of the equation is: " << equation.evaluate();

}