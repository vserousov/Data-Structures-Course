#include "NiceStack.h"

template <class T>
NiceStack<T>::NiceStack(size_t capacity) {
    // initialize parameters
    this->m_capacity = capacity;
    this->iHead = 0;
}

template <class T>
size_t NiceStack<T>::size() const {
    // size is iHead
    return this->iHead;
}

template <class T>
NiceStack<T>::~NiceStack(void) {} // vector needn't be deleted

template <class T>
void NiceStack<T>::push (T newelement) throw (out_of_range) {
    // throw exception if stack is full
    if (this->iHead >= this->m_capacity) {
        throw out_of_range("Stack is full.");
    }

    // if stack is empty
    if (this->iHead == 0) {
        // minimum is equal to element
        storage.push_back(TypeElementStack(newelement, newelement));
    } else {
        // otherwise calculate new minimum
        T minimum = this->getMinimum();
        T newMinimum = minimum < newelement ? minimum : newelement;
        this->storage.push_back(TypeElementStack(newelement, newMinimum));
    }

    // increase counter
    this->iHead++;
}

template <class T>
T NiceStack<T>::pop(void) throw (out_of_range) {
    // if stack is empty
    if (this->iHead == 0) {
        throw out_of_range("Stack is empty");
    }

    // decrease counter
    this->iHead--;

    // get element
    T element = this->storage[this->iHead].first;
    
    // delete from vector
    storage.pop_back();

    return element;
}

template <class T>
T NiceStack<T>::getMinimum(void) throw(out_of_range) {
    // if stack is empty
    if (this->iHead == 0) {
        throw out_of_range("Stack is empty");
    }

    // return minimum O(1)
    return this->storage[this->iHead - 1].second;
}
