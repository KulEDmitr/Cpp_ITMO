#include "system.h"
#include "../figures/Circle.h"
#include "../figures/Rectangle.h"

system::system() : size(0) {
    set = std::vector<Figure *>(0);
}

void system::help() {
    std::cout << "Hello, you use the simple data storage. It may include Circles and Rectangles\n"
                 "0 - see that menu\n"
                 "1 - add new figure to storage\n"
                 "2 - view all figures in storage\n"
                 "3 - get overall square\n"
                 "4 - get overall perimeter\n"
                 "5 - get system's center of mass\n"
                 "6 - get overall memory\n"
                 "7 - get sorted list of all figures\n"
                 "8 - finish work and exit" << std::endl;
}

void system::add_figure() {
    std::cout << "If you want to add Circle, enter 1"
                 "\nIf you want to add Rectangle, enter 2"
              << std::endl;
    int command;
    std::cin >> command;
    switch (command) {
        case 1:
            set.push_back(new Circle());
            set[size]->initFromDialog();
            ++size;
            break;
        case 2:
            try {
                set.push_back(new Rectangle());
                set[size]->initFromDialog();
                ++size;
                break;
            } catch (std::runtime_error &err) {
                std::cout << err.what() << std::endl;
            }
        default:
            throw std::runtime_error("Unknown command");
    }

}

void system::show_all_figures() {
    for (int i = 0; i < size; ++i) {
        std::cout << "Figure number " + std::to_string(i) << std::endl;
        set[i]->draw();
    }
}

void system::calculate_square() {
    double square = 0;
    for (int i = 0; i < size; ++i) {
        square += set[i]->square();
    }
    std::cout << "overall square is: " + std::to_string(square) << std::endl;
}

void system::calculate_perimeter() {
    double perimeter = 0;
    for (int i = 0; i < size; ++i) {
        perimeter += set[i]->perimeter();
    }
    std::cout << "overall square is: " + std::to_string(perimeter) << std::endl;
}

void system::calculate_center() {
    double mas_rad_x = 0;
    double mas_rad_y = 0;
    double mas = 0;
    for (int i = 0; i < size; ++i) {
        double m = set[i]->mass();
        mas += m;
        mas_rad_x += m * set[i]->position().x;
        mas_rad_y += m * set[i]->position().y;
    }
    Vector2D pos;
    pos.x = mas_rad_x / mas;
    pos.y = mas_rad_y / mas;
    std::cout << "Center of system's mass is:" << std::endl;
    pos.draw();
}

void system::calculate_memory() {
    double memory = 0;
    for (int i = 0; i < size; ++i) {
        memory += set[i]->size();
    }
    std::cout << "overall used memory is: " + std::to_string(memory) << std::endl;
}

void system::show_sorted_list() {
    std::sort(set.rbegin(), set.rend());
    show_all_figures();
}

void system::run() {
    help();
    int command = 0;
    while (command != EXIT) {
        std::cout << "\nPlease, enter the command" << std::endl;
        std::cin >> command;
        switch (command) {
            case HELP:
                help();
                break;
            case ADD:
                add_figure();
                break;
            case SHOW_ALL:
                show_all_figures();
                break;
            case SQUARE:
                calculate_square();
                break;
            case PERIMETER:
                calculate_perimeter();
                break;
            case CENTER_OF_MASS:
                calculate_center();
                break;
            case MEMORY:
                calculate_memory();
                break;
            case GET_SORTED:
                show_sorted_list();
                break;
            case EXIT:
                break;
            default:
                throw std::runtime_error("Unknown command");
        }
    }
}
