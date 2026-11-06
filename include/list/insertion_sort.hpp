#pragma once

#include <iostream>
#include "vector.hpp"

namespace dsac::list {

template <typename List>
void insertion_sort(List& data){
    for (int i = 1; i < vec.size(); i++) {
        T key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}
    

}  // namespace dsac::list
