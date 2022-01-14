#include <iostream>
#include "DoublyLinkedList.h"
#include "DoublyLinkedListMF.h"

int main() {

    std::cout << "Doubly Linked List" << std::endl;
    DoublyLinkedList<double> list;
    list.add(1);
    list.add(4);
    list.add(9);
    list.add(16);
    list.add(25);



    // Once reference is taken uncomment the next line and comment the one after
    //list[2] = 3.3;
    *list[2] = 3.3;

    std::cout << "The Value of third element with index 2 is " << list[2]->getData() << std::endl;
    std::cout << std::endl;

    // Check if the next links are functional
    std::cout << "Print list" << std::endl;
    list.printLinkedList();
    std::cout << "" << std::endl;

    list.deleteNode(list[3]);

    // Check if the next links are still functional after deleting third node
    std::cout << "Print list after deleting third element" << std::endl;
    list.printLinkedList();
    std::cout << "" << std::endl;


    list.deleteNode(list[3]);

    // Check if the next links are still functional after deleting last node
    std::cout << "Print list after deleting last element" << std::endl;
    list.printLinkedList();
    std::cout << "" << std::endl;


    list.deleteNode(list[0]);

    // Check if the next links are still functional after deleting first node
    std::cout << "Print list after deleting first element" << std::endl;
    list.printLinkedList();
    std::cout << "" << std::endl;


    // Check if the previous links are functional
    std::cout << "Print list in reverse order" << std::endl;
    list.printRevers();
    std::cout << "" << std::endl;



    // Dynamic Doubly Link List
    std::cout << "Dynamic Doubly Linked List" << std::endl;
    DoublyLinkedList<double> *l2 = new DoublyLinkedList<double>();


    l2->add(1);
    l2->add(4);
    l2->add(9);
    l2->add(16);
    l2->add(25);
    // To delete the dnode
    // list.deleteNode(list[2]);

    std::cout << "The Value of third element with index 2 is " << (*l2)[2]->getData() << std::endl; //linked list is first dereferenced.
    std::cout << std::endl;


    // Doubly Linked List with Move to Front method
    DoublyLinkedListMF<double> listMF;
    listMF.add(1);
    listMF.add(4);
    listMF.add(9);
    listMF.add(16);
    listMF.add(25);

    std::cout << "Doubly Linked List with move to front method" << std::endl;
    listMF.printLinkedList();
    std::cout << std::endl;

    listMF.at(3);

    std::cout << "Doubly Linked List with move to front method after accessing the fourth element (index 3)"
              << std::endl;
    listMF.printLinkedList();
    std::cout << std::endl;

    listMF[3];

    std::cout << "Doubly Linked List with move to front method after another access to the fourth element (index 3)"
              << std::endl;
    listMF.printLinkedList();
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

