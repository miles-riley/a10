#pragma once

#include "array/vector.hpp"
#include "list/doubly_linked.hpp"

#include "stackqueue/stack.hpp"
#include "stackqueue/queue.hpp"

#include <string>
#include <stdexcept>

// std::string remove_duplicates(std::string input);

// std::string clean_backspace_string(std::string input);

// template <typename T, typename StackContainer=dsac::array::Vector<T>, typename QueueContainer=dsac::array::Vector<T>>
// bool stack_contains(dsac::stackqueue::stack<T, StackContainer>& st, dsac::stackqueue::queue<T, QueueContainer>& qu, const T& elt);


std::string remove_duplicates(std::string input) {
    dsac::stackqueue::stack<char> st;
    
    for (char c : input) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    std::string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    std::reverse(result.begin(), result.end());
    return result;
}


std::string clean_backspace_string(std::string input) {
    dsac::stackqueue::stack<char> st;
    
    for (char c : input) {
        if (c == '<') {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(c);
        }
    }
    
    std::string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

template <typename T, typename StackContainer, typename QueueContainer>
bool stack_contains(
    dsac::stackqueue::stack<T, StackContainer>& st, 
    dsac::stackqueue::queue<T, QueueContainer>& qu, 
    const T& elt){

    if(!qu.empty()){
        throw std::invalid_argument("Q must be initially empty.");
    }

    bool found = false;

    while(!st.empty()){
        if(st.top() == elt){
            found = true;
        }
        qu.push(st.top());
        st.pop();
    }

    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }

    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }

    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }

    return found;
}