#pragma once

#include <vector>
#include <algorithm>

#include "../figures/abstract/Figure.h"
#include "../figures/Circle.h"
#include "../figures/Rectangle.h"

/*
Функционал системы:
- Хранение множества фигур

- Динамическое добавление фигур пользователем. (через консоль) = 1
- Отобразить все фигуры = 2.
- Суммарная площадь всех фигур - 3.
- Суммарный периметр всех фигур - 4.
- Центр масс всей системы - 5.
- Память, занимаемая всеми экземплярами классов - 6.
- Сортировка фигур между собой по массе - 7
- Завершить работу - 8.
*/

class system {
    enum commands {
        HELP = 0,
        ADD = 1,
        SHOW_ALL = 2,
        SQUARE = 3,
        PERIMETER = 4,
        CENTER_OF_MASS = 5,
        MEMORY = 6,
        GET_SORTED = 7,
        EXIT = 8
    };

    std::vector<Figure *> set;
    int size;

    system() : size(0) {
        set = std::vector<Figure *>(0);
    };

    static void help() {
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
    };
    void add_figure() {
        std::cout << "If you want to add Circle, enter 1"
                     "\nIf you want to add Rectangle, enter 2"
                  << std::endl;
        int command;
        std::cin >> command;
        switch (command) {
            case 1:
                set.push_back(new Circle());
                set[size]->initFromDialog();
                break;
            case 2:
                set.push_back(new Rectangle());
                set[size]->initFromDialog();
                break;
            default:
                throw std::runtime_error("Unknown command");
        }
        ++size;
    };
    void show_all_figures() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Figure number " + std::to_string(i) << std::endl;
            set[i]->draw();
        }
    };
    void calculate_square() {
        double square = 0;
        for (int i = 0; i < size; ++i) {
            square += set[i]->square();
        }
        std::cout << "overall square is: " + std::to_string(square) << std::endl;
    };
    void calculate_perimeter() {
        double perimeter = 0;
        for (int i = 0; i < size; ++i) {
            perimeter += set[i]->perimeter();
        }
        std::cout << "overall square is: " + std::to_string(perimeter) << std::endl;
    };
    void calculate_center() {
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
    };
    void calculate_memory() {
        double memory = 0;
        for (int i = 0; i < size; ++i) {
            memory += set[i]->size();
        }
        std::cout << "overall used memory is: " + std::to_string(memory) << std::endl;

    };
    void show_sorted_list() {
        std::sort(set.rbegin(), set.rend());
        show_all_figures();
    };

public:
    static system& get_instance() {
        static system instance;
        return instance;
    }

    system(system *other) = delete;
    system& operator=(system&) = delete;

    void run() {
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
};
