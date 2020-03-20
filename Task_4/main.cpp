#include <iostream>
#include "util/system.h"

int main() {
    try{
        system::get_instance().run();
    } catch (std::runtime_error &err) {
        std::cerr << err.what() << std::endl;
    }
    return 0;
}
