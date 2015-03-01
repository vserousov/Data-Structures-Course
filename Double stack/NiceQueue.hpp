#include "NiceQueue.h"

template <class T>
NiceQueue<T>::NiceQueue(size_t capacity) : inStack(capacity), outStack(capacity) {
    // queue capacity
    this->m_capacity = capacity;
}

template <class T>
size_t NiceQueue<T>::size(void) const {
    // Size of queue is equal to sum of stack sizes
    return this->inStack.size() + this->outStack.size();
}

template <class T>
void NiceQueue<T>::enq(T newElement) throw(out_of_range) {
    // inStack is full
    if (this->inStack.size() == this->m_capacity) {
        throw out_of_range("Queue is full");
    }

    this->inStack.push(newElement);
}

template <class T>
T NiceQueue<T>::deq(void) throw(out_of_range) {
    // OutStack is not empty
    if (this->outStack.size() > 0) {
        return outStack.pop();
    }

    // If both stacks are empty
    if (this->inStack.size() == 0) {
        throw out_of_range("Queue is empty");
    }

    // OutStack is empty
    while (this->inStack.size() > 0) {
        this->outStack.push(this->inStack.pop());
    }

    // Get element from outStack
    return this->outStack.pop();
}

template <class T>
T NiceQueue<T>::getMinimum(void) throw (out_of_range) {

    // If both stacks are empty
    if (this->inStack.size() == 0 && this->outStack.size() == 0) {
        throw out_of_range("Queue is empty");
    }

    // If inStack is empty
    if (this->inStack.size() == 0) {
        return outStack.getMinimum();

    // If outStack is empty
    } else if (this->outStack.size() == 0) {
        return inStack.getMinimum();

    // If both stacks are not empty
    } else {
        T element1 = inStack.getMinimum();
        T element2 = outStack.getMinimum();
        return element1 < element2 ? element1 : element2;
    }

}