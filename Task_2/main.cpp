#include <iostream>
#include <random>

#include "menu.h"

int main() {
    menu helper = menu();
    std::string result;

    for (int i = 0; i < 15; ++i) {
        helper.take_command(result);
    }
    return 0;
}
