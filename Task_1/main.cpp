#include "procedures.h"

//var 9
int main() {

    {
        std::cout << "\nTask 1: \tChanges the values of two input variables to each other." << std::endl;
        int a = 10, b = 5;

        std::cout << "before: a = " << a << "\tb = " << b << std::endl;

        int& a_1 = a;
        swap(a_1, b);
        std::cout << "after_1 (links): a = " << a << "\tb = " << b << std::endl;

        swap(&a, &b);
        std::cout << "after_2 (pointer): a = " << a << "\tb = " << b << std::endl;
    }

    {
        std::cout << "\nTask 4: \tDiscards its fractional part from a real number" << std::endl;

        double a = 10.9765, b = 45.567890;

        std::cout << "before: a = " << a << "\tb = " << b << std::endl;

        floor(a);
        floor(&b);

        std::cout << "after: a = " << a << "\tb = " << b << std::endl;
    }

    {
        std::cout
                << "\nTask 9: \tMultiplies the complex variable by the second argument of the procedure - real number"
                << std::endl;

        complex z_1 = complex(0.1, 7), z_2 = complex(0.3, 0.6);
        double a = 0.05;
        std::cout << "before: z_1 = " << z_1 << "\tz_2 = " << z_2 << "\tr_n = " << a << std::endl;

        mult_compl_real(z_1, a);
        mult_compl_real(&z_2, &a);

        std::cout << "after: z_1 = " << z_1 << "\tz_2 = " << z_2 << std::endl;
    }

    {
        std::cout << "\nTask 12: \tShifts the circle by a given vector" << std::endl;

        circle c_1 = circle(1, 1, 8), c_2 = circle(0.7, 5, 2.5);
        vector v = vector(6.6, 7);
        std::cout << "before: c_1 = " << c_1 << "\tc_2 = " << c_2 << "\tvector = " << v << std::endl;

        move_circle(c_1, v);
        move_circle(&c_2, &v);

        std::cout << "after: c_1 = " << c_1 << "\tc_2 = " << c_2 << std::endl;
    }

    return 0;
}