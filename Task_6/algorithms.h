#pragma once

#include <iterator>

template<typename iterator, typename object>
bool any_of(const iterator begin, const iterator end, bool (*func)(object)) {
    for (iterator it = begin; it != end; it = std::next(it)) {
        if (func(*it)) {
            return true;
        }
    }
    return false;
}

template<typename iterator, typename object>
bool one_of(const iterator begin, const iterator end, bool (*func)(object)) {
    bool one = false;
    for (iterator it = begin; it != end; it = std::next(it)) {
        if (func(*it)) {
            if (one) {
                return false;
            }
            one = true;
        }
    }
    return one;
}

template<typename iterator, typename object>
bool is_palindrome(const iterator begin, const iterator end, bool (*compare)(object, object)) {
    for (iterator first = begin, last = std::prev(end);
         first != last; first = std::next(first), last = std::prev(last)) {
        if (!compare(*first, *last)) {
            return false;
        }
    }
    return true;
}
