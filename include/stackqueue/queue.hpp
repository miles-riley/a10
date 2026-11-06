#pragma once

#include "array/vector.hpp"
#include "list/doubly_linked.hpp"

namespace dsac::stackqueue {
/// A simplified version of the STL queue class
template <typename T, typename Container=dsac::list::DoublyLinkedList<T>>
class queue {
    private:
        Container data;

    public:
        /// return the number of elements currently in the queue
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

        /// add an element to the back of the queue
        void push(const T& elem);

        /// remove the first element from the queue
        void pop();
};

template <typename T, typename Container>
int queue<T, Container>::size() const{
    return int(data.size());
}
 
template <typename T, typename Container>
bool queue<T, Container>::empty() const{
    return data.empty();
}
 
template <typename T, typename Container>
const T& queue<T, Container>::front() const{
    return data.front();
}
 
template <typename T, typename Container>
T& queue<T, Container>::front(){
    return data.front();
}
 
template <typename T, typename Container>
const T& queue<T, Container>::back() const{
    return data.back();
}
 
template <typename T, typename Container>
T& queue<T, Container>::back(){
    return data.back();
}
 
template <typename T, typename Container>
void queue<T, Container>::push(const T& elem){
    data.push_back(elem);
}
 
template <typename T, typename Container>
void queue<T, Container>::pop(){
    data.pop_front();


}  // namespace dsac::stackqueue
