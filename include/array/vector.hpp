#pragma once
#include <algorithm> // max
#include <stdexcept> // out_of_range and invalid_argument
#include <utility> // move

namespace dsac::array {
///Simplified version of std::vector
/// @tparam T the element type    
template <typename T>
class Vector {
    private:
        /// capacity of the array
        int cap{0};

        /// number of actual entries
        int sz{0};

        /// pointer to array of elements
        T* data{nullptr};

        void clone(const Vector<T>& other);
        void transfer(Vector<T>& other);

    public:
        class iterator {
            friend class Vector;
            private:
                Vector* vec;
                int ind;

            public:
                iterator(Vector* v = nullptr, int i = -1) : vec{v}, ind{i} {}
                T* operator->() const{return &(*vec)[ind];}
                T& operator*() const{return (*vec)[ind];}

                iterator& operator++() {
                    ++ind;
                    return *this;
                };

                iterator operator++(int) {
                    iterator old(*this);
                    ++ind;
                    return old;
                };

                iterator& operator--() {
                    --ind;
                    return *this;
                };

                iterator operator--(int){
                    iterator old(*this);
                    --ind;
                    return old;
                };
                
                bool operator==(const iterator it) const{
                    return vec == it.vec && ind == it.ind;
                }

                bool operator!=(const iterator it) const{
                    return !(*this == it);
                }

        };

        class const_iterator {
            friend class Vector;
            private:
                const Vector* vec;
                int ind;

            public:
                const_iterator(const Vector* v = nullptr, int i = -1) : vec{v}, ind{i} {}
                const T* operator->() const{return &(*vec)[ind];}
                const T& operator*() const{return (*vec)[ind];}

                const_iterator& operator++(){
                    ++ind;
                    return *this;
                };

                const_iterator operator++(int){
                    const_iterator old(*this);
                    ++ind;
                    return old;
                };

                const_iterator& operator--(){
                    --ind;
                    return *this;
                };

                const_iterator operator--(int){
                    const_iterator old(*this);
                    --ind;
                    return old;
                };
                
                bool operator==(const const_iterator it) const{
                    return vec == it.vec && ind == it.ind;
                }

                bool operator!=(const const_iterator it) const{
                    return !(*this == it);
                }
        };

        /// TODO: Constructs an empty vector
        Vector();

        /// TODO: Constructs a vector with the specified number of elements
        /// Each Element is Value Initialized
        /// @param n number of elements in the vector
        /// @throw std::invalid_argument if n is negative
        Vector(int n);


        /// TODO: Returns the current capacity of the underlying array
        /// @return the size of the underlying array
        int capacity() const;


        /// TODO: Returns the number of elements stored
        /// @return the number of elements stored
        int size() const;


        /// TODO: Tests whether the vector is empty.
        /// @return true if the vector is empty, false otherwise
        bool empty() const;


        /// TODO:Tests whether the vector is empty.
        /// Returns const reference to the element at index i;
        /// behavior is undefined if i is out of bounds
        /// @param i index of desired element
        /// @return element at index i
        const T& operator[](int i) const;


        /// TODO: Tests whether the vector is empty.
        /// Returns reference to the element at index i;
        /// behavior is undefined if i is out of bounds
        /// @param i index of desired element
        /// @return element at index i
        T& operator[](int i);


        /// TODO: Returns const reference to the element at index i;
        /// raises out_of_range exception with invalid index
        /// @param i index of desired element
        /// @return element at index i
        /// @throw out_of_range exception if index is invalid for current vector
        const T& at(int i) const;


        /// TODO: Returns reference to the element at index i;
        /// raises out_of_range exception with invalid index
        /// @param i index of desired element
        /// @return element at index i
        /// @throw out_of_range exception if index is invalid for current vector
        T& at(int i);


        /// TODO: Returns a const reference to the first element;
        /// behavior is undefined if vector is empty
        /// @return reference to first element
        const T& front() const;


        /// TODO: Returns a live reference to the first element;
        /// behavior is undefined if vector is empty
        /// @return reference to first element
        T& front();


        /// TODO: Returns a const reference to the last element;
        /// behavior is undefined if vector is empty
        /// @return reference to last element
        const T& back() const;


        /// TODO: Returns a live reference to the last element;
        /// behavior is undefined if vector is empty
        /// @return reference to last element
        T& back();


        /// TODO: Inserts an element at end of the vector
        /// @param elem   the new element
        void push_back(const T& elem);


        /// TODO: Removes the last element from the vector
        /// Calls shrink() after removing the element to reduce unused capacity when appropriate
        /// Behavior is undefined if the vector is empty
        void pop_back();


        /// TODO: Inserts an element at index i;
        /// behavior is undefined if i is out of bounds
        /// @param i      index at which new element should be placed
        /// @param elem   the new element
        void insert(int i, const T& elem);


        /// TODO: Removes the element at index i and shifts subsequent elements left
        /// Calls shrink() after removing the element to reduce unused capacity when appropriate
        /// Behavior is undefined if i is out of bounds
        /// @param i index of element to be removed
        void erase(int i);


        /// TODO: Requests that the vector capacity be at least as large as the indicated capacity
        /// The function has no effect if the current capacity is already large enough
        /// @param minimum the minimum capacity after the operation
        void reserve(int minimum);
    

        /// TODO: Changes the capacity of the vector to new_cap
        /// Existing elements are preserved in their current order
        /// new_cap must be at least as large as the current size
        /// If new_cap is 0, no array is allocated
        /// @param new_cap the new capacity of the vector
        void reallocate(int new_cap);


        /// TODO: Reduces the capacity of the vector when there is substantial unused space
        /// If the size is at most one-fourth of the current capacity, reduces the capacity by half
        /// This function does not reduce the capacity below 1
        void shrink();

        
        /// TODO: Removes unused capacity from the vector
        /// Reduces the capacity to match the current size
        /// If the vector is empty, the capacity becomes 0
        /// The function has no effect if capacity is already equal to size
        void shrink_to_fit();

    public:
        /// TODO: Destructor
        ~Vector();

        /// Copy constructor will be defined later
        Vector(const Vector& other);

        /// Copy assignment will be defined later
        Vector& operator=(const Vector& other);

        /// Move constructor will be defined later
        Vector(Vector&& other);

        /// Move assignment will be defined later
        Vector& operator=(Vector&& other);

        iterator insert(iterator it, const T& elem){
            insert(it.ind, elem);
            return it;
        }

        iterator erase(iterator it){
            erase(it.ind);
            return it;
        }

        iterator begin() {
            return iterator(this, 0);
        }
        iterator end() {
            return iterator(this, sz);
        }
        const_iterator begin() const {
            return const_iterator(this, 0);
        }
        const_iterator end() const {
            return const_iterator(this, sz);
        }
    
}; // Vector class


template <typename T>
Vector<T>::Vector(){}

template <typename T>
Vector<T>::Vector(int n){
    if(n < 0){
        throw std::invalid_argument("n cannot be negative");
    }

    cap = n;
    sz = n;

    if(n > 0){
        data = new T[n]();
    }
}

template <typename T>
int Vector<T>::capacity() const{
    return cap;
}

template <typename T>
int Vector<T>::size() const{
    return sz;
}

template <typename T>
bool Vector<T>::empty() const{
    return sz == 0;
}

template <typename T>
const T& Vector<T>::operator[](int i) const{
    return data[i];
}

template <typename T>
T& Vector<T>::operator[](int i){
    return data[i];
}

template <typename T>
const T& Vector<T>::at(int i) const{
    if(i < 0 || i >= sz){
        throw std::out_of_range("index out of range");
    }

    return data[i];
}

template <typename T>
T& Vector<T>::at(int i){
    if(i < 0 || i >= sz){
        throw std::out_of_range("index out of range");
    }

    return data[i];
}

template <typename T>
const T& Vector<T>::front() const{
    return data[0];
}

template <typename T>
T& Vector<T>::front(){
    return data[0];
}

template <typename T>
const T& Vector<T>::back() const{
    return data[sz - 1];
}

template <typename T>
T& Vector<T>::back(){
    return data[sz - 1];
}

template <typename T>
void Vector<T>::push_back(const T& elem){
    insert(sz, elem);
}

template <typename T>
void Vector<T>::pop_back(){
    sz--;
    shrink();
}

template <typename T>
void Vector<T>::insert(int i, const T& elem){
    T copy = elem;

    if(sz == cap){
        reallocate(std::max(1, 2 * cap));
    }

    for(auto j = sz; j > i; j--){
        data[j] = std::move(data[j - 1]);
    }

    data[i] = std::move(copy);
    sz++;
}

template <typename T>
void Vector<T>::erase(int i){
    for(auto j = i; j < sz - 1; j++){
        data[j] = std::move(data[j + 1]);
    }

    sz--;
    shrink();
}

template <typename T>
void Vector<T>::reserve(int minimum){
    if(minimum > cap){
        reallocate(minimum);
    }
}

template <typename T>
void Vector<T>::reallocate(int new_cap){
    T* new_data = nullptr;

    if(new_cap > 0){
        new_data = new T[new_cap]();
    }

    for(auto i = 0; i < sz; i++){
        new_data[i] = std::move(data[i]);
    }

    delete[] data;
    data = new_data;
    cap = new_cap;
}

template <typename T>
void Vector<T>::shrink(){
    if(cap > 1 && sz <= cap / 4){
        reallocate(std::max(1, cap / 2));
    }
}

template <typename T>
void Vector<T>::shrink_to_fit(){
    if(cap == sz){
        return;
    }

    reallocate(sz);
}

template <typename T>
Vector<T>::~Vector(){
    delete[] data;
}

template <typename T>
void Vector<T>::clone(const Vector<T>& other){
    cap = other.cap;
    sz = other.sz;
    data = new T[cap];
    for(auto i{0}; i < sz; i++){
        data[i] = other.data[i];
    }
}

template <typename T>
void Vector<T>::transfer(Vector<T>& other){
    cap = other.cap;
    sz = other.sz;
    data = other.data;
    other.data = nullptr;
    other.cap = 0;
    other.sz = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other){
    clone(other); 
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    if(this != &other){
        delete[] data;
        clone(other);
    }
    return *this;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other){
    transfer(other); 
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other){
    if(this != &other){
        delete[] data;
        transfer(other);
    }
    return *this;
}

}  // namespace dsac::array