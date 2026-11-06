//include/matrix.hpp
#pragma once

#include "vector.hpp"
#include <stdexcept>  // std::out_of_range

namespace dsac::array{
class Matrix {
    private:
        int rows{0};
        int cols{0};
        dsac::array::Vector<dsac::array::Vector<int>> data;

    public:
        /// TODO:
        /*
        if r < 0 OR c < 0 
            throw std::out_of_range("Negative dimensions");
        rows = r
        cols = c
        for i from 0 to rows-1
            declare row vector of ints
            for j from 0 to cols-1
                append 0 to row  // initialize each element with 0
            append row to data
        */
        Matrix(int r, int c);

        /// TODO:
        //data.at(i).at(j)
        int& operator()(int i, int j);

        // TODO:
        // throw std::out_of_range("dimensions must match")
        // result(i, j) = (*this)(i, j) + other(i, j)
        Matrix operator+(Matrix& other);
};

inline Matrix::Matrix(int r, int c){
    if(r < 0 || c < 0){
        throw std::out_of_range("can't have negative rows or columns");
    }

    rows = r;
    cols = c;

    for(auto i{0}; i < rows; i++){
        dsac::array::Vector<int> vec(rows);
        for(auto j{0}; j < cols; j++){
            vec.push_back(0);
        }
        data.push_back(vec);
    }
};

inline int& Matrix::operator()(int i, int j){
    if(i > rows - 1 || i < 0 || j > cols - 1 || j < 0){
        throw std::out_of_range("index out of vector range");
    }    

    return data.at(i).at(j);
}

inline Matrix Matrix::operator+(Matrix& other){
    if(rows != other.rows || cols != other.cols){
        throw std::out_of_range("matrices dimensions don't match");
    }

    Matrix result(rows, cols);

    for(auto i = 0; i < rows; i++){
        for(auto j = 0; j < cols; j++){
            result.data.at(i).at(j) = data.at(i).at(j) + other.data.at(i).at(j);
        }
    }

    return result;
}

}