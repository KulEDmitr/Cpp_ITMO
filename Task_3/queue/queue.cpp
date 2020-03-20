#include <cmath>
#include <stdexcept>
#include "queue.h"

queue::queue() : head(0), tail(-1), length(0) {
    data = new int[SIZE]{};
}

queue::~queue() {
    delete[] data;
}

queue &queue::operator<<=(int a) {
    if (length != SIZE) {
        tail = get_next(tail);
        data[tail] = a;
        ++length;
    } else {
        throw std::runtime_error("we are totally full, please, try again later!");
    }
    return *this;
}

queue &queue::operator>>=(int &a) {
    if (length != 0) {
        a = data[head];
        head = get_next(head);
        --length;
    } else {
        throw std::runtime_error(
                "the last guy was the least, sorry!");
    }
    return *this;
}

queue operator<<(queue a, int b) {
    return a <<= b;
}

queue operator>>(queue a, int &b) {
    return a >>= b;
}


std::string queue::to_string() const {
    std::string res = "Hello, I'm a queue with " + std::to_string(length) + " elements:\n[";
    int h = head;
    for (int i = 0; i < length; ++i) {
        res.append(" " + std::to_string(data[(h + i) % SIZE]));
    }
    return res + "]";
}

int queue::get_next(int cur) const {
    return (cur + 1) % SIZE;
}

std::ostream &operator<<(std::ostream &s, queue const &a) {
    s << a.to_string();
    return s;
}

std::istream &operator>>(std::istream &s, queue &a) {
    int data = 0;
    while (s >> data) {
        a >>= data;
    }
    return s;
}
