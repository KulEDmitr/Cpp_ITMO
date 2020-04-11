#pragma once

#include "../exceptions/simpleException.h"
#include <string>

template<int N, typename T>
class queue {
    char *data;
    int size,
        head,
        tail;

    int get_next(int cur) const  {
        return (cur + 1) % N;
    }

public:
    explicit queue(int size = 0, const T &value = T()) : size(size), head(0), tail(size) {
        if (size >= N || size < 0) {
            throw simpleException("Check size!");
        }
        data = new char[N * sizeof(T)];
        T *ptr = (T *) data;
        for (size_t i = 0; i < size; ++i) {
            new(ptr + i) T(value);
        }
        for (size_t i = size; i < N; ++i) {
            new(ptr + i) T();
        }
    }

    queue(const queue<N, T> &other) : size(other.size), head(0) {
        data = new char[N * sizeof(T)];
        T *ptr = (T *) data;
        tail = other.head;
        for (size_t i = 0; i < size; ++i) {
            new(ptr + i) T(other[tail]);
            tail = get_next(tail);
        }
        for (size_t i = size; i < N; ++i) {
            new(ptr + i) T();
        }
    }

    ~queue() {
        T *ptr = (T *) data;
        for (size_t i = 0; i < size; ++i) {
            ptr[head].~T();
            head = get_next(head);
        }
        delete[] data;
    }

    bool empty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }
    T* getData() const {
        return data;
    }

    queue<N, T> &operator=(const queue &other) {
        if (this != &other) {
            queue(other).swap(*this);
        }
        return *this;
    }

    T &front() {
        if (empty()) {
            throw simpleException("Queue is empty");
        }
        return ((T *) data)[head];
    }

    T &back() {
        if (empty()) {
            throw simpleException("Queue is empty");
        }
        return ((T *) data)[tail - 1];
    }

    void push(const T &value = T()) {
        if (size == N) {
            throw simpleException("we are totally full, please, try again later!");
        }
        T *ptr = (T *) data;
        *(ptr + tail) = T(value);
        tail = get_next(tail);
        ++size;
    }

    void pop() {
        if (empty()) {
            throw simpleException("the last guy was the least, sorry!");
        }
        head = get_next(head);
        --size;
    }

    friend std::ostream &operator<<(std::ostream &s, queue<N, T> const &a) {
        s << "Hello, I'm a queue with " << a.size << " elements:\n[";
        int h = a.head;
        T* ptr = (T* ) a.data;
        for (size_t i = 0; i < a.size; ++i) {
            s << "\t " << i + 1 << " " << ptr[(h + i) % N];
        }
        s << "]" << std::endl;
        return s;
    }

    friend std::istream &operator>>(std::istream &s, queue<N, T> &a) {
        T newData;
        while (s >> newData) {
            a.push(newData);
        }
        return s;
    }
};
