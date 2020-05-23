#include "CircularBuffer.h"

int main() {
    CircularBuffer<int> data(10);
    std::cout << data << std::endl;

    for (int i = 0; i < 6; ++i) {
        std::cout
                << "Please, integer element that will be added to buffer\nEnter command {0 - add to begin, 1 - add to last}";
        int el, comm;
        std::cin >> el >> comm;

        if (comm) {
            data.addLast(el);
        } else {
            data.addFirst(el);
        }
        std::cout << data << std::endl;
    }

    std::cout << "Erase fourth element via iterator\n";
    iterator<int> it = 4 + data.begin();
    data.remove(it);
    std::cout << data << std::endl << "iterator value after erasing: " << *it;

    for (int i = 0; i < 3; ++i) {
        std::cout
                << "Please, enter integer element that will be insert to buffer via iterator\nEnter position for insertion";

        int el, pos;
        std::cin >> el >> pos;
        data.add(data.begin() + pos, el);
        std::cout << "Current data\n" << data << std::endl;
    }

    std::cout << "\nAccess to first and last elements:\n";
    std::cout << "\tfirst: " << data.readFirst() << '\n';
    std::cout << "\tlast: " << data.readLast() << '\n';

    std::cout << "Change buffer capacity to 11:" << '\n';
    data.changeCapacity(11);
    std::cout << data << std::endl;

    data.addFirst(678);
    std::cout << data << std::endl;

    std::cout << "Change buffer capacity to 5:" << '\n';
    data.changeCapacity(5);

    std::cout << "Showing all elements via []: " << '\n';
    for (int i = 0; i < data.getSize(); ++i)
        std::cout << data[i] << ' ';

    std::cout << "Data via standard algorithm:\n";
    iterator<int> ans = std::min_element(data.begin(), data.end());
    std::cout << data << std::endl << *ans << std::endl;
}
