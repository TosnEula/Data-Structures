#include <iostream>
#include "node.h"
#include "LinkedList.h"

int main() {
    LinkedList<double> list;
    list.add(1);
    list.add(4);
    list.add(9);
    list.add(16);
    list.add(25);

    // To delete the node
    // list.deleteNode(list[2]);

    std::cout << list[2]->getData() << std::endl;
    std::cout << std::endl<< std::endl<< std::endl;

    // Once reference is taken uncomment the next line and comment the one after
    //list[2] = 3.3;
    *list[2] = 3.3;

    std::cout << list[2]->getData() << std::endl;
    std::cout << std::endl<< std::endl<< std::endl;

    list.printLinkedList();

    return EXIT_SUCCESS;
}

