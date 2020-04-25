#include <iostream>
#include <vector>

#include "cat.h"
#include "algorithms.h"

using namespace std;

bool getInt(int a) {
    return a == 1;
}

bool equalInt(int a, int b) {
    return a == b;
}

bool isSmall(const cat &kit) {
    return kit.isSmall();
}

bool equalsCat(const cat &first, const cat &second) {
    return first.isSmall() == second.isSmall();
}

int main() {
    vector<int> ints_1 = {1, 2, 3};
    vector<int> ints_2 = {1, 2, 2, 2, 1};

    cout << any_of(ints_1.begin(), ints_1.end(), getInt) << endl; //true
    cout << one_of(ints_1.begin(), ints_1.end(), getInt) << endl; //true
    cout << one_of(ints_2.begin(), ints_2.end(), getInt) << endl; //false
    cout << is_palindrome(ints_1.begin(), ints_1.end(), equalInt) << endl; //false
    cout << is_palindrome(ints_2.begin(), ints_2.end(), equalInt) << endl; //true

    vector<cat> cats = {cat("Vasiliy", false), cat("Don", true), cat("Gav", true), cat("Pin", true), cat("Don", false)};

    cout << any_of(cats.begin(), cats.end(), isSmall) << endl; //true
    cout << one_of(cats.begin(), cats.end(), isSmall) << endl; //false
    cout << is_palindrome(cats.begin(), cats.end(), equalsCat) << endl; //true

    return 0;
}
