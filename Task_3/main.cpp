#include "triangle/triangle.h"
#include "queue/queue.h"

/*
Написать программу, проверяющую правильность работы операторов – для наглядности и лучшего
усвоения материала использовать как явный, так и не явный метод вызова функций
операторов (см. пример в конце задания).
*/

//task_1
void compare_triangles() {
    std::cout << std::endl;
    triangle t1, t2;
    std::cout << "___Task_1___\nPlease, enter the coordinates for two triangles" << std::endl;
    std::cin >> t1 >> t2;

    //неявно
    std::cout << "Triangles for analyzing:\n\tfirst\n" << t1 << "\n\tsecond\n" << t2 << std::endl;

    std::cout << "\n---Comparison operators---" << std::endl;
    //неявно
    if (t1 == t2) {
        std::cout << "Triangles are equal" << std::endl;
    }
    //явно
    if (operator!=(t1, t2)) {
        std::cout << "Triangles aren't equal" << std::endl;
    }
    //неявно
    if (t1 < t2) {
        std::cout << "First triangle is smaller than second" << std::endl;
    }
    //явно
    if (operator>(t1, t2)) {
        std::cout << "First triangle is larger than second" << std::endl;
    }
}

void move_triangle() {
    std::cout << std::endl;
    vector v;
    triangle t1;

    std::cout << "___Task_1___\nPlease, enter the coordinates for start triangle" << std::endl;
    std::cin >> t1;

    std::cout << "Now, enter the vector for moving" << std::endl;
    std::cin >> v;

    std::cout << "\n---Moving (operator+)---" << std::endl;
    //неявно
    triangle t2 = t1 + v;
    //явно
    //triangle t2 = operator+(t1, v);
    //triangle t2 = operator+(v, t1);

    //неявно
    std::cout << "Triangles for analyzing:\n\tfirst\n" << t1 << "\n\tsecond\n" << t2
              << "\n\nLet's check it for equality" << std::endl;

    //проверим, что не сломали треугольник при перемещении
    //явно
    if (operator==(t1, t2)) {
        std::cout << "Triangles are equal. Win!!" << std::endl;
    } else {
        std::cout << "Triangles aren't equal. Check your code for bugs!" << std::endl;
    }
}

void task_2() {
    std::cout << std::endl;
    queue queue;
    std::cout << "___Task_2___\nIf you want \n\tto push elements, enter '2', "
                 "\n\tto pop elements, enter '1'. \n\tto stop, enter '0'\n"
                 "!!There are no more than 100 elements in queue one time"
              << std::endl;
    int act = 1;
    while (act != 0) {
        int el;
        std::cin >> act;
        switch (act) {
            case 2 :
                try {
                    std::cout << "Enter new element" << std::endl;
                    std::cin >> el;
                    //явно
                    queue.operator<<=(el);
                    std::cout << "Element " + std::to_string(el) + " was successfully added" << std::endl;
                } catch (std::runtime_error &err) {
                    std::cout << err.what()
                              << "\nIf you want to pop elements, enter '1',\n\tto stop, enter '0'"
                              << std::endl;
                }
                break;
            case 1:
                try {
                    //неявно
                    queue >>= el;
                    std::cout << el << std::endl;
                } catch (std::runtime_error &err) {
                    std::cout << err.what()
                              << "\nIf you want to push elements, enter '2',\n\tto stop, enter '0'"
                              << std::endl;
                }
                break;
            case 0:
                //неявно
                std::cout << queue << "\nYou are finish this session" << std::endl;
                break;
            default:
                throw std::runtime_error("Unknown operation with queue");
        }
    }
}

int main() {
    try {
        //task_1
        compare_triangles();
        move_triangle();
        //task_2
        task_2();
    } catch (std::runtime_error &err) {
        std::cout << err.what() << std::endl;
    }
    return 0;
}
