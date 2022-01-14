#include <iostream>
#include <stdexcept>
#include "dnode.h"

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<typename T>
class DoublyLinkedList {
    dnode<T> *head;
    dnode<T> *tail;
    uint64_t length;
public:
    uint64_t getLength() const {
        return length;
    }

    // Linked List Constructor
    DoublyLinkedList() {
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
            tail->setNext(new dnode<T>(data));
            tail->getNext()->setPrev(tail);
            tail = tail->getNext();
            length++;
        } else { // if linkedlist empty
            head = new dnode<T>(data);
            tail = head;
            length++;
        }
    }

    // Linked List push front
    void pushFront(T data) {
        if (head) {
            head = new dnode<T>(data, head);
            length++;
        } else {
            head = new dnode<T>(data, head);
            tail = head;
            length++;
        }
    }

    // Linked list insert after
    void insertAfter(dnode<T> *referenceNode, T data) {
        if (!head) {
            return;
        }
        dnode<T> *p = head;
        while (p) {
            if (p == referenceNode) {
                break;
            }
            p = p->getNext();
        }
        if (!p) {
            return;
        }
        p->setNext(new dnode<T>(data, p->getNext()));
        p->getNext()->setPrev(p);
        if (p == tail) {
            tail = p->getNext();
        } else {
            p->getNext()->getNext()->setPrev(p->getNext());
        }
        length++;
    }


    // Linked List print function
    void printLinkedList() {
        dnode<T> *p = head;
        while (p != nullptr) {
            std::cout << p->getData() << std::endl;
            p = p->getNext();
        }
    }

    // Linked List print in reverse order function
    void printRevers() {
        dnode<T> *p = tail;
        while (p != nullptr) {
            std::cout << p->getData() << std::endl;
            p = p->getPrev();
        }
    }

    // Access the linked list like an array
	virtual dnode<T> *at(uint64_t index) { 				//virtual added later to override
        if (index >= length) {
            throw std::runtime_error("Error: you should not access an element outside of the range.");
        }
        dnode<T> *p = head;
        for (uint64_t i = 0; i < index; i++) p = p->getNext();
        return p;
    }

    // Once we take the overloading with reference, you can uncomment this definition and uncomment the previous definition
//    dnode<T> &at(uint64_t index) {
//        if (index >= length) {
//            throw std::runtime_error("Error: you should not access an element outside of the range.");
//        }
//        dnode<T> *p = head;
//        for (uint64_t i = 0; i < index; i++) p = p->getNext();
//        return *p;
//    }

    // Use array notation to access the linked list like an array
    dnode<T> *operator[](uint64_t index) {
        return at(index);
    }

    // Once we take the overloading with reference, you can uncomment this definition and uncomment the previous definition
//    dnode<T> &operator[](uint64_t index) {
//        return at(index);
//    }


    // Delete a dnode
    void deleteNode(dnode<T> *nodeToBeDeleted) {
        if (!head) {
            return;
        }
        if (nodeToBeDeleted == head) {
            head = head->getNext();
            head->setPrev(nullptr);
            delete nodeToBeDeleted;
        } else {
            dnode<T> *p = head;
            while (p->getNext()) {
                if (p->getNext() == nodeToBeDeleted) {
                    p->setNext(nodeToBeDeleted->getNext());
                    if (p->getNext() != nullptr) {
                        p->getNext()->setPrev(p);
                    } else {
                        tail = p;
                    }
                    delete nodeToBeDeleted;
                    length--;
                    break;
                }
                p = p->getNext();
            }
        }
    }

    // Linked List Destructor
    virtual ~DoublyLinkedList() {
        dnode<T> *p = nullptr;
        while (head) {
            p = head;
            delete p;
            head = head->getNext();
        }
    }

protected:
    dnode<T> *getHead() const {
        return head;
    }

    dnode<T> *getTail() const {
        return tail;
    }

    void setHead(dnode<T> *head) {
        DoublyLinkedList::head = head;
    }

    void setTail(dnode<T> *tail) {
        DoublyLinkedList::tail = tail;
    }

};


#endif //DOUBLYLINKEDLIST_H
