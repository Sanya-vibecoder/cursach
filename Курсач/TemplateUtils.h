#pragma once
#include <iostream>

template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}

template <typename T>
T bigger(T a, T b) {
    return (a > b) ? a : b;
}#pragma once
