#ifndef SAFEARRAY_H
#define SAFEARRAY_H

template <class T> 
class safearray {

  private:
    T *storage;
    int capacity;
  
  public:
    safearray() : storage(NULL), capacity(0) {} // default constructor
    safearray(int); // single param constructor
    ~safearray(void); // destructor
    T& operator[] (int) const throw(out_of_range); 
};

template <class T>
safearray<T>::safearray(int length) {
    storage = new T[length];
    capacity = length;
}

template <class T>
safearray<T>::~safearray() {
    delete[] storage;
}

template <class T>
T& safearray<T>::operator[] (int index) const throw(out_of_range) {
    if (index < 0) {
        throw out_of_range("Index is below 0");
    }

    if (index >= capacity) {
        throw out_of_range("Index is too high");
    }

    return storage[index];
}

#endif
