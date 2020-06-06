#pragma once
#include <vector>

#include "../entities/CubeRubi.h"

struct act{
    int side;
    bool direction;

    explicit act(int side = 0, bool direction = true) : side(side), direction(direction) {};
};

typedef std::vector<act*> actionsList;
typedef std::vector<int> conditionsList;

class Automaton {
    CubeRubi* cube;
    int state;

    conditionsList getAut1() const;
    conditionsList getAut2() const;
    conditionsList getAut3() const;
    conditionsList getAut4() const;
    conditionsList getAut5() const;
    conditionsList getAut6() const;
    conditionsList getAut7() const;

    actionsList steps1() const;
    actionsList steps2()const;
    actionsList steps3()const;
    actionsList steps4()const;
    actionsList steps5()const;
    actionsList steps6()const;
    actionsList steps7()const;
    actionsList steps8()const;
    actionsList steps9()const;
    actionsList steps10()const;
    actionsList steps11()const;
    actionsList steps12()const;
    actionsList steps13()const;
    actionsList steps14()const;
    actionsList steps15()const;
    actionsList steps16()const;
    actionsList steps17()const;
    actionsList steps18()const;
    actionsList steps19()const;
    actionsList steps20()const;
    actionsList steps21()const;
    actionsList steps22()const;
    actionsList steps23()const;
    actionsList steps24()const;
    actionsList steps25()const;

    actionsList mainSteps(int) const;

    static void addAction(actionsList* curList, int, bool);
    static bool exist(int, conditionsList&);
    static bool isEqual(int, int, int, int, int, int) ;

public:
    bool success;
    int automaton;

    explicit Automaton(CubeRubi* mem = nullptr) : state(0), automaton(0), success(false), cube(mem) {}
    ~Automaton();

    void clean();
    void next(actionsList&);
};
