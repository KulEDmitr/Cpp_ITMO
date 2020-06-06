#include "Automaton.h"

Automaton::~Automaton() {
    cube->~CubeRubi();
    cube = nullptr;
}

void Automaton::clean() {
    state = 0;
    automaton = 0;
    success = false;
}

bool Automaton::exist(int st, conditionsList &curCond) {
    for (int &it : curCond) {
        if (it == st) {
            return true;
        }
    }
    return false;
}

bool Automaton::isEqual(int a, int b, int c, int d, int e, int f) {
    return (a == d && b == e && c == f) || (a == d && b == f && c == e)
           || (a == e && b == d && c == f) || (a == e && b == f && c == d)
           || (a == f && b == d && c == e) || (a == f && b == e && c == d);
}

void Automaton::addAction(actionsList *curList, int s, bool d) { curList->push_back(new act(s, d)); }

void Automaton::next(actionsList &list) {
    actionsList object;
    conditionsList aut1, aut2, aut3, aut4, aut5, aut6, aut7;
    switch (automaton) {
        case 0:
            aut1 = getAut1();
            switch (state) {
                case 0:
                    for (auto i = 1; i < 26; ++i) {
                        if (exist(i, aut1)) {
                            state = i;
                            list = mainSteps(i);
                            return;
                        }
                    }
                    break;
                case 28:
                    state = 0;
                    ++automaton;
                    break;
                case 25:
                case 26:
                case 27:
                    if (exist(25, aut1)) {
                        ++state;
                        list = steps25();
                        return;
                    }
                default:
                    state = 0;
                    break;
            }
            break;
        case 1:
            aut2 = getAut2();
            switch (state) {
                case 0:
                    for (auto i = 1; i < 26; ++i) {
                        if (exist(i, aut2)) {
                            state = i;
                            list = mainSteps(i);
                            return;
                        }
                    }
                    break;
                case 28:
                    state = 0;
                    ++automaton;
                    break;
                case 25:
                case 26:
                case 27:
                    if (exist(25, aut2)) {
                        ++state;
                        list = steps25();
                        return;
                    }
                default:
                    state = 0;
                    break;
            }
            break;
        case 2:
            aut3 = getAut3();
            switch (state) {
                case 0:
                    for (int i = 1; i < 9; ++i) {
                        if (exist(i, aut3)) {
                            state = i;
                            list = mainSteps(i);
                            return;
                        }
                    }

                    if (exist(13, aut3)) {
                        state = 9;
                        list = steps13();
                        return;
                    }
                    break;
                case 9:
                case 10:
                case 11:
                    if (exist(13, aut3)) {
                        ++state;
                        list = steps13();
                    }
                    for (int i = 1; i < 9; ++i) {
                        if (exist(i, aut3)) {
                            state = 0;
                            break;
                        }
                    }
                    break;
                case 12:
                    for (int i = 9; i < 13; ++i) {
                        if (exist(i, aut3)) {
                            state = i + 4;
                            list = mainSteps(i);
                        }
                    }
                    state = 17;
                    break;
                case 17:
                    ++automaton;
                default:
                    state = 0;
                    break;
            }
            break;
        case 3:
            aut4 = getAut4();
            switch (state) {
                case 8:
                    state = 0;
                    ++automaton;
                    break;
                case 0:
                    for (int i = 1; i < 8; ++i) {
                        if (exist(i, aut4)) {
                            state = i;
                            list = mainSteps(i);
                            return;
                        }
                    }
                default:
                    state = 8;
                    break;
            }
            break;
        case 4:
            aut5 = getAut5();
            switch (state) {
                case 0:
                    for (int i = 1; i < 4; ++i) {
                        if (exist(i, aut5)) {
                            state = i;
                            list = mainSteps(i);
                            return;
                        }
                    }
                case 1:
                case 2:
                case 3:
                    state = 4;
                    break;
                case 4:
                    for (int i = 4; i < 6; ++i) {
                        if (exist(i, aut5)) {
                            state = i + 1;
                            list = mainSteps(i);
                            return;
                        }
                    }
                case 5:
                case 6:
                    state = 7;
                    break;
                case 7:
                    if (exist(6, aut5)) {
                        state = 8;
                        list = steps6();
                        return;
                    }
                    state = 8;
                    break;
                case 8:
                    state = 0;
                    ++automaton;
                default:
                    break;
            }
            break;
        case 5:
            aut6 = getAut6();
            switch (state) {
                case 0:
                    for (int i = 1; i < 4; ++i) {
                        if (exist(i, aut6)) {
                            state = i;
                            list = mainSteps(i);
                            return;
                        }
                    }
                case 1:
                case 2:
                case 3:
                    state = 4;
                    break;
                case 4:
                    for (int i = 4; i < 6; ++i) {
                        if (exist(i, aut6)) {
                            state = i + 1;
                            list = mainSteps(i);
                            return;
                        }
                    }
                case 5:
                case 6:
                    state = 7;
                    break;
                case 7:
                    state = 0;
                    ++automaton;
                default:
                    break;
            }
            break;
        case 6:
            aut7 = getAut7();
            switch (state) {
                case 0:
                    for (int i = 1; i < 3; ++i) {
                        if (exist(i, aut7)) {
                            state = i;
                            list = mainSteps(i);
                            return;
                        }
                    }
                    state = 3;
                    break;
                case 1:
                case 2:
                case 3:
                    state = 4;
                    list = steps3();
                    return;
                case 4:
                    for (int i = 1; i < 3; ++i) {
                        if (exist(i, aut7)) {
                            state = i + 8;
                            list = mainSteps(i);
                            return;
                        }
                    }
                    state = 11;
                    break;
                case 9:
                case 10:
                case 11:
                    state = 12;
                    list = steps3();
                    return;
                case 12:
                    for (int i = 1; i < 3; ++i) {
                        if (exist(i, aut7)) {
                            state = i + 12;
                            list = mainSteps(i);
                            return;
                        }
                    }
                    state = 15;
                    break;
                case 13:
                case 14:
                    if (exist(3, aut7)) {
                        state = 18;
                    } else {
                        state = 16;
                        list = steps3();
                        return;
                    }
                    break;
                case 15:
                case 16:
                case 17:
                    if (exist(3, aut7)) {
                        state = 18;
                    } else {
                        ++state;
                        list = steps3();
                        return;
                    }
                    break;
                case 18:
                    ++automaton;
                    success = true;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    list = object;
}

conditionsList Automaton::getAut1() const {
    conditionsList aut;

    if (cube->getColor(2, 2) == 2 && cube->getColor(6, 8) == 1) {
        aut.push_back(1);
    }
    if (cube->getColor(3, 2) == 3 && cube->getColor(6, 6) == 1) {
        aut.push_back(2);
    }
    if (cube->getColor(5, 2) == 5 && cube->getColor(6, 4) == 1) {
        aut.push_back(3);
    }
    if (cube->getColor(4, 2) == 4 && cube->getColor(6, 2) == 1) {
        aut.push_back(4);
    }
    if (cube->getColor(2, 2) == 1 && cube->getColor(6, 8) == 2) {
        aut.push_back(5);
    }
    if (cube->getColor(3, 2) == 1 && cube->getColor(6, 6) == 2) {
        aut.push_back(6);
    }
    if (cube->getColor(5, 2) == 1 && cube->getColor(6, 4) == 5) {
        aut.push_back(7);
    }
    if (cube->getColor(4, 2) == 1 && cube->getColor(6, 2) == 4) {
        aut.push_back(8);
    }
    if (cube->getColor(2, 6) == 1) {
        aut.push_back(9);
    }
    if (cube->getColor(3, 6) == 1) {
        aut.push_back(10);
    }
    if (cube->getColor(5, 6) == 1) {
        aut.push_back(11);
    }
    if (cube->getColor(4, 6) == 1) {
        aut.push_back(12);
    }
    if (cube->getColor(2, 4) == 1) {
        aut.push_back(13);
    }
    if (cube->getColor(3, 4) == 1) {
        aut.push_back(14);
    }
    if (cube->getColor(5, 4) == 1) {
        aut.push_back(15);
    }
    if (cube->getColor(4, 4) == 1) {
        aut.push_back(16);
    }
    if (cube->getColor(2, 8) == 1) {
        aut.push_back(17);
    }
    if (cube->getColor(3, 8) == 1) {
        aut.push_back(18);
    }
    if (cube->getColor(5, 8) == 1) {
        aut.push_back(19);
    }
    if (cube->getColor(4, 8) == 1) {
        aut.push_back(20);
    }
    if (cube->getColor(2, 8) != 2 && cube->getColor(1, 2) == 1) {
        aut.push_back(21);
    }
    if (cube->getColor(3, 8) != 3 && cube->getColor(1, 6) == 1) {
        aut.push_back(22);
    }
    if (cube->getColor(5, 8) != 5 && cube->getColor(1, 4) == 1) {
        aut.push_back(23);
    }
    if (cube->getColor(4, 8) != 4 && cube->getColor(1, 8) == 1) {
        aut.push_back(24);
    }

    if (aut.empty()) {
        aut.push_back(25);
    }

    return aut;
}
conditionsList Automaton::getAut2() const {
    conditionsList aut;

    if (cube->getColor(2, 3) == 1 && cube->getColor(3, 1) == 3 && cube->getColor(6, 9) == 2) {
        aut.push_back(1);
    }
    if (cube->getColor(5, 3) == 1 && cube->getColor(2, 1) == 2 && cube->getColor(6, 7) == 5) {
        aut.push_back(2);
    }
    if (cube->getColor(3, 3) == 1 && cube->getColor(4, 1) == 4 && cube->getColor(6, 3) == 3) {
        aut.push_back(3);
    }
    if (cube->getColor(4, 3) == 1 && cube->getColor(5, 1) == 5 && cube->getColor(6, 1) == 4) {
        aut.push_back(4);
    }
    if (cube->getColor(2, 3) == 2 && cube->getColor(3, 1) == 1 && cube->getColor(6, 9) == 3) {
        aut.push_back(5);
    }
    if (cube->getColor(5, 3) == 5 && cube->getColor(2, 1) == 1 && cube->getColor(6, 7) == 2) {
        aut.push_back(6);
    }
    if (cube->getColor(3, 3) == 3 && cube->getColor(4, 1) == 1 && cube->getColor(6, 3) == 4) {
        aut.push_back(7);
    }
    if (cube->getColor(4, 3) == 4 && cube->getColor(5, 1) == 1 && cube->getColor(6, 1) == 5) {
        aut.push_back(8);
    }
    if (cube->getColor(2, 3) == 3 && cube->getColor(3, 1) == 2 && cube->getColor(6, 9) == 1) {
        aut.push_back(9);
    }
    if (cube->getColor(5, 3) == 2 && cube->getColor(2, 1) == 5 && cube->getColor(6, 7) == 1) {
        aut.push_back(10);
    }
    if (cube->getColor(3, 3) == 4 && cube->getColor(4, 1) == 3 && cube->getColor(6, 3) == 1) {
        aut.push_back(11);
    }
    if (cube->getColor(4, 3) == 5 && cube->getColor(5, 1) == 3 && cube->getColor(6, 1) == 1) {
        aut.push_back(12);
    }
    if (cube->getColor(2, 9) == 1) {
        aut.push_back(13);
    }
    if (cube->getColor(5, 9) == 1) {
        aut.push_back(14);
    }
    if (cube->getColor(3, 9) == 1) {
        aut.push_back(15);
    }
    if (cube->getColor(4, 9) == 1) {
        aut.push_back(16);
    }
    if (cube->getColor(3, 7) == 1) {
        aut.push_back(17);
    }
    if (cube->getColor(2, 7) == 1) {
        aut.push_back(18);
    }
    if (cube->getColor(4, 7) == 1) {
        aut.push_back(19);
    }
    if (cube->getColor(5, 7) == 1) {
        aut.push_back(20);
    }
    if (cube->getColor(1, 1) == 1 && cube->getColor(5, 9) != 5 || cube->getColor(2, 7) != 2) {
        aut.push_back(21);
    }
    if (cube->getColor(1, 3) == 1 && cube->getColor(2, 9) != 2 || cube->getColor(3, 7) != 3) {
        aut.push_back(22);
    }
    if (cube->getColor(1, 9) == 1 && cube->getColor(3, 9) != 3 || cube->getColor(4, 7) != 4) {
        aut.push_back(23);
    }
    if (cube->getColor(1, 7) == 1 && cube->getColor(4, 9) != 4 || cube->getColor(5, 7) != 5) {
        aut.push_back(24);
    }

    if (aut.empty()) {
        aut.push_back(25);
    }

    return aut;
}
conditionsList Automaton::getAut3() const {
    conditionsList aut;

    if (cube->getColor(2, 2) == 2 && cube->getColor(6, 8) == 5) {
        aut.push_back(1);
    }
    if (cube->getColor(3, 2) == 3 && cube->getColor(6, 6) == 2) {
        aut.push_back(2);
    }
    if (cube->getColor(4, 2) == 4 && cube->getColor(6, 2) == 3) {
        aut.push_back(3);
    }
    if (cube->getColor(5, 2) == 5 && cube->getColor(6, 4) == 4) {
        aut.push_back(4);
    }
    if (cube->getColor(2, 2) == 2 && cube->getColor(6, 8) == 3) {
        aut.push_back(5);
    }
    if (cube->getColor(5, 2) == 5 && cube->getColor(6, 4) == 2) {
        aut.push_back(6);
    }
    if (cube->getColor(4, 2) == 4 && cube->getColor(6, 2) == 5) {
        aut.push_back(7);
    }
    if (cube->getColor(3, 2) == 3 && cube->getColor(6, 6) == 4) {
        aut.push_back(8);
    }

    if (aut.empty()) {
        aut.push_back(13);
    }

    if (cube->getColor(3, 4) != 3 || cube->getColor(2, 6) != 2) {
        aut.push_back(9);
    }
    if (cube->getColor(2, 4) != 2 || cube->getColor(5, 6) != 5) {
        aut.push_back(10);
    }
    if (cube->getColor(5, 4) != 5 || cube->getColor(4, 6) != 4) {
        aut.push_back(11);
    }
    if (cube->getColor(4, 4) != 4 || cube->getColor(3, 6) != 3) {
        aut.push_back(12);
    }

    return aut;
}
conditionsList Automaton::getAut4() const {
    conditionsList aut;

    if (cube->getColor(2, 2) == 6 && cube->getColor(3, 2) == 6 && cube->getColor(6, 2) == 6 &&
        cube->getColor(6, 4) == 6) {
        aut.push_back(1);
    }
    if (cube->getColor(2, 2) == 6 && cube->getColor(5, 2) == 6 && cube->getColor(6, 2) == 6 &&
        cube->getColor(6, 6) == 6) {
        aut.push_back(2);
    }
    if (cube->getColor(4, 2) == 6 && cube->getColor(3, 2) == 6 && cube->getColor(6, 4) == 6 &&
        cube->getColor(6, 8) == 6) {
        aut.push_back(3);
    }
    if (cube->getColor(4, 2) == 6 && cube->getColor(5, 2) == 6 && cube->getColor(6, 6) == 6 &&
        cube->getColor(6, 8) == 6) {
        aut.push_back(4);
    }
    if (cube->getColor(2, 2) == 6 && cube->getColor(4, 2) == 6 && cube->getColor(6, 4) == 6 &&
        cube->getColor(6, 6) == 6) {
        aut.push_back(5);
    }
    if (cube->getColor(3, 2) == 6 && cube->getColor(5, 2) == 6 && cube->getColor(6, 2) == 6 &&
        cube->getColor(6, 8) == 6) {
        aut.push_back(6);
    }
    if (cube->getColor(2, 2) == 6 && cube->getColor(3, 2) == 6 && cube->getColor(4, 2) == 6 &&
        cube->getColor(5, 2) == 6) {
        aut.push_back(7);
    }

    return aut;
}
conditionsList Automaton::getAut5() const {
    conditionsList aut;

    if (cube->getColor(3, 2) == 2) {
        aut.push_back(1);
    }
    if (cube->getColor(5, 2) == 2) {
        aut.push_back(2);
    }
    if (cube->getColor(4, 2) == 2) {
        aut.push_back(3);
    }
    if (cube->getColor(4, 2) == 3) {
        aut.push_back(4);
    }
    if (cube->getColor(5, 2) == 3) {
        aut.push_back(5);
    }
    if (cube->getColor(5, 2) == 3) {
        aut.push_back(6);
    }

    return aut;
}
conditionsList Automaton::getAut6() const {
    conditionsList aut;

    if (isEqual(cube->getColor(5, 3), cube->getColor(2, 1), cube->getColor(6, 7), 2, 3, 6)) {
        aut.push_back(1);
    }
    if (isEqual(cube->getColor(3, 3), cube->getColor(4, 1), cube->getColor(6, 3), 2, 3, 6)) {
        aut.push_back(2);
    }
    if (isEqual(cube->getColor(4, 3), cube->getColor(5, 1), cube->getColor(6, 1), 2, 3, 6)) {
        aut.push_back(3);
    }
    if (isEqual(cube->getColor(5, 3), cube->getColor(2, 1), cube->getColor(6, 7), 3, 4, 6)) {
        aut.push_back(4);
    }
    if (isEqual(cube->getColor(4, 3), cube->getColor(5, 1), cube->getColor(6, 1), 4, 3, 6)) {
        aut.push_back(5);
    }

    return aut;
}
conditionsList Automaton::getAut7() const {
    conditionsList aut;

    if (cube->getColor(3, 1) == 6) {
        aut.push_back(1);
    }
    if (cube->getColor(2, 3) == 6) {
        aut.push_back(2);
    }
    if (cube->getColor(2, 3) == 2 && cube->getColor(2, 1) == 2
        && cube->getColor(3, 1) == 3 && cube->getColor(3, 3) == 3
        && cube->getColor(4, 1) == 4 && cube->getColor(4, 3) == 4
        && cube->getColor(5, 1) == 5 && cube->getColor(5, 3) == 5) {
        aut.push_back(3);
    }

    return aut;
}

actionsList Automaton::mainSteps(int i) const {
    switch (i) {
        case 1:
            return steps1();
        case 2:
            return steps2();
        case 3:
            return steps3();
        case 4:
            return steps4();
        case 5:
            return steps5();
        case 6:
            return steps6();
        case 7:
            return steps7();
        case 8:
            return steps8();
        case 9:
            return steps9();
        case 10:
            return steps10();
        case 11:
            return steps11();
        case 12:
            return steps12();
        case 13:
            return steps13();
        case 14:
            return steps14();
        case 15:
            return steps15();
        case 16:
            return steps16();
        case 17:
            return steps17();
        case 18:
            return steps18();
        case 19:
            return steps19();
        case 20:
            return steps20();
        case 21:
            return steps21();
        case 22:
            return steps22();
        case 23:
            return steps23();
        case 24:
            return steps24();
        case 25:
            return steps25();
        default:
            return actionsList();
    }
}
actionsList Automaton::steps1() const {
    actionsList act;
    switch (automaton) {
        case 0:
            addAction(&act, 2, true);
            addAction(&act, 2, true);
            break;
        case 1:
            addAction(&act, 2, false);
            addAction(&act, 6, false);
            addAction(&act, 2, true);
            break;
        case 2:
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            addAction(&act, 6, true);
            addAction(&act, 2, true);
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            break;
        case 3:
            addAction(&act, 2, true);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            addAction(&act, 2, false);
            break;
        case 4:
            addAction(&act, 6, true);
            addAction(&act, 5, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            addAction(&act, 6, true);
            addAction(&act, 5, false);
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            break;
        case 5:
            addAction(&act, 2, false);
            addAction(&act, 5, false);
            addAction(&act, 2, true);
            addAction(&act, 3, false);
            addAction(&act, 2, false);
            addAction(&act, 5, true);
            addAction(&act, 2, true);
            addAction(&act, 3, true);
            break;
        case 6:
            addAction(&act, 2, false);
            addAction(&act, 3, true);
            addAction(&act, 2, true);
            addAction(&act, 3, false);
            addAction(&act, 2, false);
            addAction(&act, 3, true);
            addAction(&act, 2, true);
            addAction(&act, 3, false);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps2() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 3, true);
            addAction(&act, 3, true);
            break;
        case 1:
            addAction(&act, 5, false);
            addAction(&act, 6, false);
            addAction(&act, 5, true);
            break;
        case 2:
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            addAction(&act, 6, true);
            addAction(&act, 2, true);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            break;
        case 3:
            addAction(&act, 5, true);
            addAction(&act, 6, true);
            addAction(&act, 2, true);
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            addAction(&act, 5, false);
            break;
        case 4:
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            break;
        case 5:
            addAction(&act, 3, false);
            addAction(&act, 2, false);
            addAction(&act, 5, false);
            addAction(&act, 2, true);
            addAction(&act, 3, true);
            addAction(&act, 2, false);
            addAction(&act, 5, true);
            addAction(&act, 2, true);
            break;
        case 6:
            addAction(&act, 3, true);
            addAction(&act, 2, false);
            addAction(&act, 3, false);
            addAction(&act, 2, true);
            addAction(&act, 3, true);
            addAction(&act, 2, false);
            addAction(&act, 3, false);
            addAction(&act, 2, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps3() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 5, true);
            addAction(&act, 5, true);
            break;
        case 1:
            addAction(&act, 3, false);
            addAction(&act, 6, false);
            addAction(&act, 3, true);
            break;
        case 2:
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            break;
        case 3:
            addAction(&act, 3, true);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            addAction(&act, 3, false);
            break;
        case 4:
            addAction(&act, 6, true);
            addAction(&act, 3, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, true);
            addAction(&act, 3, false);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 3, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, true);
            addAction(&act, 3, false);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            break;
        case 5:
            addAction(&act, 2, false);
            addAction(&act, 5, false);
            addAction(&act, 4, false);
            addAction(&act, 5, true);
            addAction(&act, 2, true);
            addAction(&act, 5, false);
            addAction(&act, 4, true);
            addAction(&act, 5, true);
            break;
        case 6:
            addAction(&act, 6, false);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps4() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 4, true);
            addAction(&act, 4, true);
            break;
        case 1:
            addAction(&act, 4, false);
            addAction(&act, 6, false);
            addAction(&act, 4, true);
            break;
        case 2:
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            break;
        case 3:
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            addAction(&act, 4, false);
            break;
        case 4:
            addAction(&act, 6, true);
            addAction(&act, 2, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 2, true);
            addAction(&act, 6, true);
            addAction(&act, 2, false);
            addAction(&act, 6, true);
            addAction(&act, 2, true);
            break;
        case 5:
            addAction(&act, 4, false);
            addAction(&act, 3, false);
            addAction(&act, 4, true);
            addAction(&act, 5, false);
            addAction(&act, 4, false);
            addAction(&act, 3, true);
            addAction(&act, 4, true);
            addAction(&act, 5, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps5() const {
    actionsList act;
    switch (automaton) {
        case 0:
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            addAction(&act, 2, true);
            addAction(&act, 3, true);
            break;
        case 1:
            addAction(&act, 3, true);
            addAction(&act, 6, true);
            addAction(&act, 3, false);
            break;
        case 2:
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            addAction(&act, 6, true);
            addAction(&act, 2, true);
            break;
        case 3:
            addAction(&act, 2, true);
            addAction(&act, 3, true);
            addAction(&act, 6, true);
            addAction(&act, 3, false);
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            break;
        case 4:
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 5, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            addAction(&act, 6, true);
            addAction(&act, 5, false);
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            break;
        case 5:
            addAction(&act, 5, false);
            addAction(&act, 4, false);
            addAction(&act, 3, false);
            addAction(&act, 4, true);
            addAction(&act, 5, true);
            addAction(&act, 4, false);
            addAction(&act, 3, true);
            addAction(&act, 4, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps6() const {
    actionsList act;
    switch (automaton) {
        case 0:
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            addAction(&act, 3, true);
            addAction(&act, 4, true);
            break;
        case 1:
            addAction(&act, 2, true);
            addAction(&act, 6, true);
            addAction(&act, 2, false);
            break;
        case 2:
            addAction(&act, 6, true);
            addAction(&act, 2, true);
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            break;
        case 3:
            addAction(&act, 3, true);
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            break;
        case 4:
            addAction(&act, 6, true);
            addAction(&act, 3, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, true);
            addAction(&act, 3, false);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps7() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            addAction(&act, 5, true);
            addAction(&act, 2, true);
            break;
        case 1:
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            break;
        case 2:
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            break;
        case 3:
            addAction(&act, 2, true);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            addAction(&act, 2, false);
            addAction(&act, 3, true);
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps8() const {
    actionsList act;
    switch (automaton) {
        case 0:
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            addAction(&act, 4, true);
            addAction(&act, 5, true);
            break;
        case 1:
            addAction(&act, 5, true);
            addAction(&act, 6, true);
            addAction(&act, 5, false);
            break;
        case 2:
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps9() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 2, false);
            addAction(&act, 6, false);
            addAction(&act, 2, true);
            break;
        case 1:
            addAction(&act, 3, true);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, true);
            addAction(&act, 3, false);
            break;
        case 2:
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            addAction(&act, 6, true);
            addAction(&act, 2, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps10() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 3, false);
            addAction(&act, 6, false);
            addAction(&act, 3, true);
            break;
        case 1:
            addAction(&act, 2, true);
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 2, true);
            addAction(&act, 6, true);
            addAction(&act, 2, false);
            break;
        case 2:
            addAction(&act, 6, true);
            addAction(&act, 2, true);
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps11() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 5, false);
            addAction(&act, 6, false);
            addAction(&act, 5, true);
            break;
        case 1:
            addAction(&act, 4, true);
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, true);
            addAction(&act, 4, false);
            break;
        case 2:
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps12() const {
    actionsList act;
    switch (automaton) {
        case 0:
            addAction(&act, 4, false);
            addAction(&act, 6, false);
            addAction(&act, 4, true);
            break;
        case 1:
            addAction(&act, 5, true);
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            addAction(&act, 6, true);
            addAction(&act, 6, true);
            addAction(&act, 5, true);
            addAction(&act, 6, true);
            addAction(&act, 5, false);
            break;
        case 2:
            addAction(&act, 6, true);
            addAction(&act, 4, true);
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            addAction(&act, 6, true);
            addAction(&act, 3, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps13() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 2, true);
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            break;
        case 1:
            addAction(&act, 2, false);
            addAction(&act, 6, false);
            addAction(&act, 2, true);
            break;
        case 2:
            addAction(&act, 6, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps14() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 3, true);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            break;
        case 1:
            addAction(&act, 5, false);
            addAction(&act, 6, false);
            addAction(&act, 5, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps15() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 5, true);
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            break;
        case 1:
            addAction(&act, 3, false);
            addAction(&act, 6, false);
            addAction(&act, 3, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps16() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 4, true);
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            break;
        case 1:
            addAction(&act, 4, false);
            addAction(&act, 6, false);
            addAction(&act, 4, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps17() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 2, true);
            addAction(&act, 2, true);
            addAction(&act, 6, false);
            addAction(&act, 2, true);
            addAction(&act, 2, true);
            break;
        case 1:
            addAction(&act, 2, false);
            addAction(&act, 6, false);
            addAction(&act, 2, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps18() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 3, true);
            addAction(&act, 3, true);
            addAction(&act, 6, false);
            addAction(&act, 3, true);
            addAction(&act, 3, true);
            break;
        case 1:
            addAction(&act, 5, false);
            addAction(&act, 6, false);
            addAction(&act, 5, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps19() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 5, true);
            addAction(&act, 5, true);
            addAction(&act, 6, false);
            addAction(&act, 5, true);
            addAction(&act, 5, true);
            break;
        case 1:
            addAction(&act, 3, false);
            addAction(&act, 6, false);
            addAction(&act, 3, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps20() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 4, true);
            addAction(&act, 4, true);
            addAction(&act, 6, false);
            addAction(&act, 4, true);
            addAction(&act, 4, true);
            break;
        case 1:
            addAction(&act, 4, false);
            addAction(&act, 6, false);
            addAction(&act, 4, true);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps21() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 2, true);
            addAction(&act, 2, true);
            addAction(&act, 6, false);
            addAction(&act, 2, true);
            addAction(&act, 2, true);
            break;
        case 1:
            addAction(&act, 2, true);
            addAction(&act, 6, false);
            addAction(&act, 2, false);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps22() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 3, true);
            addAction(&act, 3, true);
            addAction(&act, 6, false);
            addAction(&act, 3, true);
            addAction(&act, 3, true);
            break;
        case 1:
            addAction(&act, 3, true);
            addAction(&act, 6, false);
            addAction(&act, 3, false);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps23() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 5, true);
            addAction(&act, 5, true);
            addAction(&act, 6, false);
            addAction(&act, 5, true);
            addAction(&act, 5, true);
            break;
        case 1:
            addAction(&act, 4, true);
            addAction(&act, 6, false);
            addAction(&act, 4, false);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps24() const {
    actionsList act;

    switch (automaton) {
        case 0:
            addAction(&act, 4, true);
            addAction(&act, 4, true);
            addAction(&act, 6, false);
            addAction(&act, 4, true);
            addAction(&act, 4, true);
            break;
        case 1:
            addAction(&act, 5, true);
            addAction(&act, 6, false);
            addAction(&act, 5, false);
            break;
        default:
            break;
    }

    return act;
}
actionsList Automaton::steps25() const {
    actionsList act;

    switch (automaton) {
        case 0:
        case 1:
            addAction(&act, 6, true);
        default:
            break;
    }

    return act;
}
