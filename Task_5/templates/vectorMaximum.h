#pragma once

#include <vector>

template<typename T>
T getMax(T* data, int size) {
    T max = data[0];
    for (size_t el = 0; el < size; ++el) {
        if (max < data[el]) {
            max = data[el];
        }
    }
    return max;
}
