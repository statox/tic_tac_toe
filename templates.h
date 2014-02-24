#ifndef TEMPLATES_H_INCLUDED
#define TEMPLATES_H_INCLUDED

#include <vector>
#include <algorithm>
#include <iostream>

template< typename T>
void show(std::vector< T > A)
{
    for(std::size_t i = 0; i < A.size(); ++i) {
        std::cout << A[i] << ", ";
    }
}

template< typename T>
void show(std::vector< vector < T > > A)
{
    for(std::size_t i = 0; i < A.size(); ++i) {
        show(A[i]);
        cout << endl;
    }
}

template< typename T>
void isEgal(std::vector< T > A, std::vector< T > B)
{
    for(std::size_t i = 0; i < A.size(); ++i) {
        for (std::size_t j = 0; j < B.size(); ++j){

        }
    }
}

template<typename T>
void removeDuplicates(std::vector<T>& vec)
{
    sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

#endif // TEMPLATES_H_INCLUDED
