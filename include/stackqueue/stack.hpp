#pragma once

#include "array/vector.hpp"
#include "list/doubly_linked.hpp"


namespace dsac::stackqueue {
/// A simplified version of the STL stack
template <typename T, typename Container=dsac::array::Vector<T>>
class stack {
    private:
        Container data;

    public:
        /// return the number of elements currently in the stack
        int size() const;
        
        /// return whether the stack is currently empty
        bool empty() const;

        /// return const reference to the top element of the stack
        const T& top() const;

        /// return live (non-const) reference to the top element of the stack
        T& top();

        /// add an element to the top of the stack
        void push(const T& elem);

        /// remove the top element from the stack
        void pop();
};

template <typename T, typename Container>
int stack<T, Container>::size() const{
    return int(data.size());
}

template <typename T, typename Container>
bool stack<T, Container>::empty() const{
    return data.empty();
}

template <typename T, typename Container>
const T& stack<T, Container>::top() const{
    return data.back();
}

template <typename T, typename Container>
T& stack<T, Container>::top(){
    return data.back();
}

template <typename T, typename Container>
void stack<T, Container>::push(const T& elem){
    data.push_back(elem);
}

template <typename T, typename Container>
void stack<T, Container>::pop(){
    data.pop_back();
}

}  // namespace dsac::stackqueue