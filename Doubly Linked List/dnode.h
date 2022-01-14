#ifndef DNODE_H
#define DNODE_H

template<typename T>
class dnode {
    T data;
    dnode *next;
    dnode *prev;
public:
    dnode() {
        next = nullptr;
        prev = nullptr;
    }

    dnode(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }

    dnode(T data, dnode *next) {
        this->data = data;
        this->next = next;
        prev = nullptr;
    }

    dnode(T data, dnode *next, dnode *prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        dnode::data = data;
    }

    dnode *getNext() const {
        return next;
    }

    void setNext(dnode *next) {
        dnode::next = next;
    }

    void operator=(T data) {
        this->data = data;
    }

    dnode *getPrev() const {
        return prev;
    }

    void setPrev(dnode *prev) {
        dnode::prev = prev;
    }
};


#endif //DNODE_H
