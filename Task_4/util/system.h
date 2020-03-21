#pragma once

#include <vector>
#include <algorithm>

#include "../figures/abstract/Figure.h"

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

    system();

    static void help();
    void add_figure();
    void show_all_figures();
    void calculate_square();
    void calculate_perimeter();
    void calculate_center();
    void calculate_memory();
    void show_sorted_list();

public:
    static system &get_instance() {
        static system instance;
        return instance;
    }

    system(system *other) = delete;

    system &operator=(system &) = delete;

    void run();
};
