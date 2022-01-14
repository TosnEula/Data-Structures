#include <iostream>
#include <stdexcept>
#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList {
    node<T> *head;
    node<T> *tail;
    uint64_t length;
public:
    uint64_t getLength() const {
        return length;
    }

    // Linked List Constructor
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // Linked List add function
    void add(T data) { // Same as pushBack
        pushBack(data);
    }

    // Linked List push back
    void pushBack(T data) {
        if (head) {  // Check head not equal to nullptr ( linked list is not empty )
            tail->setNext(new node<T>(data));
            tail = tail->getNext();
            length++;
        } else { // if linkedlist empty
            head = new node<T>(data);
            tail = head;
            length++;
        }
    }

    // Linked List push front
    void pushFront(T data) {
        if (head) {
            head = new node<T>(data, head);
            length++;
        } else {
            head = new node<T>(data, head);
            tail = head;
            length++;
        }
    }

    // Linked list insert after
    void insertAfter(node<T> *referenceNode, T data) {
        if (!head) {
            return;
        }
        node<T> *p = head;
        while (p) {
            if (p == referenceNode) {
                break;
            }
            p = p->getNext();
        }
        if (!p) {
            return;
        }
        p->setNext(new node<T>(data, p->getNext()));
        if (p == tail) {
            tail = p->getNext();
        }
        length++;
    }


    // Linked List print function
    void printLinkedList() {
        node<T> *p = head;
        while (p != nullptr) {
            std::cout << p->getData() << std::endl;
            p = p->getNext();
        }
    }

    // Access the linked list like an array
    node<T> *at(uint64_t index) {
        if (index >= length) {
            throw std::runtime_error("Error: you should not access an element outside of the range.");
        }
        node<T> *p = head;
        for (uint64_t i = 0; i < index; i++) p = p->getNext();
        return p;
    }

    // Once we take the overloading with reference, you can uncomment this definition and uncomment the previous definition
    node<T> &at(uint64_t index) {
        if (index >= length) {
            throw std::runtime_error("Error: you should not access an element outside of the range.");
			      }
        node<T> *p = head;
        for (uint64_t i = 0; i < index; i++) p = p->getNext();
        return *p;
    }

    // Use array notation to access the linked list like an array
    node<T> *operator[](uint64_t index) {
        return at(index);
    }

    // Once we take the overloading with reference, you can uncomment this definition and uncomment the previous definition
    node<T> &operator[](uint64_t index) {
        return at(index);
    }


    // Delete a node
    void deleteNode(node<T> *nodeToBeDeleted) {
        if (!head) {
            return;
        }
        if (nodeToBeDeleted == head) {
            head = head->getNext();
            delete nodeToBeDeleted;
        } else {
            node<T> *p = head;
            while (p->getNext()) {
                if (p->getNext() == nodeToBeDeleted) {
                    p->setNext(nodeToBeDeleted->getNext());
                    delete nodeToBeDeleted;
                }
                p = p->getNext();
            }
        }
    }

    // Linked List Destructor
    virtual ~LinkedList() {
        node<T> *p = nullptr;
        while (head) {
            p = head;
            delete p;
            head = head->getNext();
        }
    }
};


#endif //LINKEDLIST_H
