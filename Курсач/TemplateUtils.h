#pragma once
#include <iostream>

// Template function to print an array
template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}

// Template function to return the larger of two values
template <typename T>
T bigger(T a, T b) {
    return (a > b) ? a : b;
}
