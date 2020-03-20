#pragma once

#include <iostream>

const int SIZE = 100;

class queue {
    int *data;
    int head;
    int tail;
    int length;

public:
    queue();
    ~queue();

    int get_next(int) const;
    std::string to_string() const;
    queue &operator<<=(int);
    queue &operator>>=(int &);
};

queue operator<<(queue, int);
queue operator>>(queue , int&);

std::ostream &operator<<(std::ostream &s, queue const &a);
std::istream &operator>>(std::istream &s, queue &a);
