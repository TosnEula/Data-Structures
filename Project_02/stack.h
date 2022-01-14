#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#ifndef STACK_H
#define STACK_H


template <typename T>
class Stack
{
    //Defining variables
    std::vector<T> *stack;
	uint32_t size=0;


    //Constructor that defines the size of the stack
	public:
	Stack(uint32_t size)
	{
		stack = new std::vector<T> ();
        stack->reserve(size);
        this->size = size;

	}

    //puts an element on the top of the stack
	void push (T entity)
    {
        //If the stack is currently full alert the user and return
        if (Size() == size)
        {
            std::cout << "The stack is full please remove some data" << std::endl;
            return;
        }

        //Add the element to the top of the stack
        stack->push_back(entity);

    }

    //Removes the top most element in the stack
    void pop()
    {
        //If the stack is already empty alert the user and return
        if (stack->size() == 0)
        {
            std::cout<< "The stack is empty" << std::endl;
            return;
        }
        stack->pop_back();

    }

    //Prints the current amount of variables in the stack
    uint32_t Size()
    {
        return stack->size();
    }


    //Prints the variable at the top of the stack
    T top()
    {

        return stack->back();
    }

    //Prints all the variables in the stack
    void printStack()
    {
        //loop to print each element in the stack starting from the top
        for (int i=stack->size()-1; i>-1;i--)
        {
            std::cout << stack->at(i) <<std::endl;
        }
    }


    //This function perform calculations from given value in polish notation
    double evaluate()
    {
        //Defining variables
        //Some variables are static so that once the recursion is called it will stay
        double var1, var2, convertedValue;
        static char operation = ' ';
        static std::vector<char> storeOperation;
        static int cycle=0;
        std::vector<int> storeVar2;

        //loops until the stack is empty
        while (Size() != 0)
        {
            //assigns the variable "currentValue" to the value at the top of the stack
            std::string currentValue = top();
            //Removes the value on the top of the stack to be used in the next iteration
            stack->pop_back();

            //Conditional statement to choose which part of the equation is being filled.
            switch(cycle)
            {
                //Assigns the variable "operation" with the operator at the beginning of the polish notation
                case 0:
                    operation = currentValue[0];
                    break;
                //Assigns variable 2
                case 1:
                    //conditional statement should the next value in the stack be an operator
                    if (currentValue == "+" || currentValue == "-" || currentValue == "x" || currentValue == "/")
                    {
                        //Store the operator
                        storeOperation.push_back(operation);
                        operation = currentValue[0];
                        //recursively call back the function to find the of var2
                        var2 = evaluate();
                        //set cycle back to 1, to continue going through the operation before the recursive call
                        cycle = 1;

                        //return the operator that was being used before the recurisve call
                        operation = storeOperation.back();

                        //remove the operator from the vector
                        storeOperation.pop_back();
                    }
                    //If not the next value is not an operator assign variable 2 to the next value on the stack
                    else
                    {
                        convertedValue = std::stod(currentValue);
                        var2 = convertedValue;
                    }
                    break;
                //Assign the next variable in the stack to variable 1
                case 2:
                    //conditional statement should the next value in the stack be an operator
                    if (currentValue == "+" || currentValue == "-" || currentValue == "x" || currentValue == "/")
                    {
                        //set cycle to one, to reassign the value of variable 2 once it has been recursively called.
                        cycle = 1;

                        //Store the operator
                        storeOperation.push_back(operation);

                        //change the variable "operation" to the current operator
                        operation = currentValue[0];

                        //store variable 2 to allow the value to be overrided once the recursion begins
                        storeVar2.push_back(var2);

                        //Recursive call the find the value of var1
                        var1 = evaluate();

                        //Return the value of variable 2 and operation after the recursion ends
                        var2 = storeVar2.back();
                        operation = storeOperation.back();

                        //Remove variable and operator from the vector
                        storeVar2.pop_back();
                        storeOperation.pop_back();
                    }
                    //If not an operator assign variable 1 to the next value on the stack
                    else
                    {

                        convertedValue = std::stod(currentValue);
                        var1 = convertedValue;
                    }
                    //conditional statement to choose what operation needs to be done on both variables
                    switch (operation)
                    {
                        case '+':
                            return var2 + var1;
                        case '-':
                            return var1 - var2;
                        case 'x':
                            return var1 * var2;
                        case '/':
                            return var1 / var2;
                        default:
                            std::cout << "Something went wrong";
                            return -1;
                    }

                }
            cycle++;
        }


    }

    //Deconstruct for the stack.
    ~Stack()
    {
        if (stack)
            delete stack;
    }


    //Getter and setter for private variables.
    uint32_t getSize() const {
        return size;
    }

    void setSize(uint32_t size) {
        Stack::size = size;
    }


};


#endif //STACK_H