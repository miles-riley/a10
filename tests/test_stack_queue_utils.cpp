#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "array/vector.hpp"
#include "list/doubly_linked.hpp"
#include "stackqueue/stack_queue_utils.hpp"

#include <vector>
#include <stdexcept>

template <typename StackType>
std::vector<int> testFileDrainStack(StackType& st) {
    std::vector<int> result;

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

template <typename QueueType>
std::vector<int> testFileDrainQueue(QueueType& qu) {
    std::vector<int> result;

    while (!qu.empty()) {
        result.push_back(qu.front());
        qu.pop();
    }

    return result;
}

template <typename StackType>
void checkStackBehavior() {
    StackType st;

    // Starts empty
    REQUIRE(st.empty());
    REQUIRE(st.size() == 0);

    // Push puts the newest element on top
    st.push(1);
    st.push(2);
    st.push(3);

    REQUIRE_FALSE(st.empty());
    REQUIRE(st.size() == 3);
    REQUIRE(st.top() == 3);

    // Top returns a live reference
    st.top() = 30;
    REQUIRE(st.top() == 30);

    // Const top reads the same element
    const StackType& const_st = st;
    REQUIRE(const_st.top() == 30);

    // Pop removes in last-in-first-out order
    st.pop();
    REQUIRE(st.size() == 2);
    REQUIRE(st.top() == 2);

    st.pop();
    REQUIRE(st.top() == 1);

    st.pop();
    REQUIRE(st.empty());
    REQUIRE(st.size() == 0);
}

template <typename QueueType>
void checkQueueBehavior() {
    QueueType qu;

    // Starts empty
    REQUIRE(qu.empty());
    REQUIRE(qu.size() == 0);

    // Front is the oldest element, back is the newest
    qu.push(1);

    REQUIRE(qu.front() == 1);
    REQUIRE(qu.back() == 1);

    qu.push(2);
    qu.push(3);

    REQUIRE_FALSE(qu.empty());
    REQUIRE(qu.size() == 3);
    REQUIRE(qu.front() == 1);
    REQUIRE(qu.back() == 3);

    // Front and back return live references
    qu.front() = 10;
    qu.back() = 30;

    REQUIRE(qu.front() == 10);
    REQUIRE(qu.back() == 30);

    // Const front and back read the same elements
    const QueueType& const_qu = qu;

    REQUIRE(const_qu.front() == 10);
    REQUIRE(const_qu.back() == 30);

    // Pop removes in first-in-first-out order
    qu.pop();

    REQUIRE(qu.size() == 2);
    REQUIRE(qu.front() == 2);
    REQUIRE(qu.back() == 30);

    qu.pop();

    REQUIRE(qu.front() == 30);
    REQUIRE(qu.back() == 30);

    qu.pop();

    REQUIRE(qu.empty());
    REQUIRE(qu.size() == 0);
}