#ifndef ENHANCEDSAFEARRAY_H
#define ENHANCEDSAFEARRAY_H

#include "safearray.h"

template <class T>
class EnhancedSafeArray : public SafeArray<T> {

public:
    EnhancedSafeArray(void);
    EnhancedSafeArray(size_t);
    EnhancedSafeArray(const EnhancedSafeArray&);
    size_t size(void) const;
    EnhancedSafeArray<T>& operator=(const EnhancedSafeArray&);
    bool operator==(const EnhancedSafeArray&);
};

template <class T>
EnhancedSafeArray<T>::EnhancedSafeArray(void) : SafeArray() {}

template <class T>
EnhancedSafeArray<T>::EnhancedSafeArray(size_t n) : SafeArray(n) {}

template <class T>
EnhancedSafeArray<T>::EnhancedSafeArray(const EnhancedSafeArray& a) {
    count = a.size();
    storage = new T[count];
    
    for (int i = 0; i < count; i++) {
        storage[i] = a[i];
    }
}

template <class T>
size_t EnhancedSafeArray<T>::size(void) const {
    return count;
}

template <class T>
EnhancedSafeArray<T>& EnhancedSafeArray<T>::operator=(const EnhancedSafeArray& a) {
    delete [] storage;
    count = a.size();
    storage = new T[count];

    for (int i = 0; i < count; i++) {
        storage[i] = a[i];
    }

    return *this;
}

template <class T>
bool EnhancedSafeArray<T>::operator==(const EnhancedSafeArray& a) {
    if (! (size() == a.size())) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (! (storage[i] == a[i])) {
            return false;
        }
    }

    return true;
}

#endif