#pragma once
#include <iostream>

struct simpleException : public std::exception {
    explicit simpleException(const char* msg) : msg(msg) {};

    const char* what() const noexcept override {
        return msg;
    }

private:
    const char* msg;
};
