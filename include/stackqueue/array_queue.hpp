// stackqueue/array_queue.hpp
/// Definition for a templated ArrayQueue class with fixed capacity

#pragma once
#include <memory>        // defines unique_ptr
#include <stdexcept>     // defines overflow_error

namespace dsac::stackqueue {

/// Implementation of a queue interface using an array with bounded capacity
/// @param T the element type
template <typename T>
class ArrayQueue {
    private:
        /// actual capacity of the underlying array
        int capacity;
        
        /// index of the front of the queue
        int f{0};

        /// current number of elements in the queue
        int sz{0};

        /// pointer to the underlying array
        std::unique_ptr<T[]> data;
        
    public:
        /// Construct a new queue with given capacity (default 1000)
        ArrayQueue(int cap = 1000);

        /// return number of elements currently in the queue
        int size() const;
        
        /// return whether the queue is currently empty
        bool empty() const;

        /// return const reference to the first element of the queue
        const T& front() const;

        /// return live (non-const) reference to the first element of the queue
        T& front();

        /// return const reference to the last element of the queue
        const T& back() const;

        /// return live (non-const) reference to the last element of the queue
        T& back();

        /// add element to the end of the queue
        /// @param elem the new element
        /// @throw overflow_error if queue is already at full capacity
        void push(const T& elem);

        /// remove the first element from the queue
        void pop();
};

template <typename T>
ArrayQueue<T>::ArrayQueue(int cap){
    capacity = cap;
    data = std::make_unique<T[]>(cap);
}

template <typename T>
int ArrayQueue<T>::size() const{
    return sz;
}

template <typename T>
bool ArrayQueue<T>::empty() const{
    return sz == 0;
}

template <typename T>
const T& ArrayQueue<T>::front() const{
    if(empty()){
        throw std::underflow_error("Queue is empty.");
    }

    return data[f];
}

template <typename T>
T& ArrayQueue<T>::front(){
    if(empty()){
        throw std::underflow_error("Queue is empty.");
    }

    return data[f];
}

template <typename T>
const T& ArrayQueue<T>::back() const{
    if(empty()){
        throw std::underflow_error("Queue is empty.");
    }

    return data[(f + sz - 1) % capacity];
}

template <typename T>
T& ArrayQueue<T>::back(){
    if(empty()){
        throw std::underflow_error("Queue is empty.");
    }

    return data[(f + sz - 1) % capacity];
}

template <typename T>
void ArrayQueue<T>::push(const T& elem){
    if(sz == capacity){
        throw std::overflow_error("Queue is at full capacity.");
    }

    data[(f + sz) % capacity] = elem;
    sz++;
}

template <typename T>
void ArrayQueue<T>::pop(){
    if(empty()){
        throw std::underflow_error("Queue is empty.");
    }

    f = (f + 1) % capacity;
    sz--;
}

}  