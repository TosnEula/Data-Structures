#include "DoublyLinkedList.h"

// Doubly Linked List with Move-to-front access strategy

#ifndef DOUBLYLINKEDLISTMF_H
#define DOUBLYLINKEDLISTMF_H

template<typename T>
class DoublyLinkedListMF : public DoublyLinkedList<T> {
public:
    dnode<T> *at(uint64_t index) {
        if (index >= this->getLength()) {
            throw std::runtime_error("Error: you should not access an element outside of the range.");
        }
        dnode<T> *p = this->getHead();
        for (uint64_t i = 0; i < index; i++) p = p->getNext();
        if (p != this->getHead()) {
            this->getHead()->setPrev(p);
            p->getPrev()->setNext(p->getNext());
            if (p != this->getTail()) {
                p->getNext()->setPrev(p->getPrev());
            }
        }
        p->setNext(this->getHead());
        p->setPrev(nullptr);
        this->setHead(p);
        return p;
    }
};

#endif //DOUBLYLINKEDLISTMF_H
