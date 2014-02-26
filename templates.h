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

template<typename T>
bool contains(std::vector<T> vec, T val)
{
    for (std::size_t i=0; i<vec.size(); i++){
        if (vec[i]==val)
            return true;
    }

    return false;
}

template<typename T>
T maxi(std::vector<T> vec)
{
    T maxi = vec[0];
    for (std::size_t i=0; i<vec.size(); i++){
        if (maxi<vec[i])
            maxi=vec[i];
    }
    return maxi;
}
template<typename T>
T mini(std::vector<T> vec)
{
    T mini = vec[0];
    for (std::size_t i=0; i<vec.size(); i++){
        if (mini>vec[i]){
            mini=vec[i];
        }
    }
    return mini;
}

template<typename T>
T indexMaxi(std::vector<T> vec)
{
    int index=0;
    T maxi = vec[0];
    for (std::size_t i=0; i<vec.size(); i++){
        if (maxi<vec[i]){
            maxi=vec[i];
            index=i;
        }
    }
    return index;
}

template<typename T>
T indexMini(std::vector<T> vec)
{
    int index=0;
    T mini = vec[0];
    for (std::size_t i=0; i<vec.size(); i++){
        if (mini>vec[i]){
            mini=vec[i];
            index=i;
        }
    }
    return index;
}

#endif // TEMPLATES_H_INCLUDED
