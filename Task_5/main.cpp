#include "exceptions/simpleException.h"
#include "templates/vectorMaximum.h"
#include "templates/queue.h"
#include "types/cat.h"
using namespace std;

void templateFunctionTest() {
    int nums[] = {6, 4, 3, 78, 45, 100};
    int res = getMax(nums, 6);
    cout << res << endl;

    cat cats[] = {cat("a"), cat("b"), cat("bbc")};
    cat c = getMax(cats, 3);
    cout << c << endl << endl;
}

void templateContainerTest() {
    queue<4, string> data(1);
    data.push("aa");
    data.push("b");
    data.push("bbc");
    try {
        data.push("beb");
    } catch(simpleException &ex) {
        cout << ex.what() << endl;
    }

    queue<4, cat> catData(0);
    catData.push(cat());
    catData.push(cat("bin"));
    catData.push(cat("richard"));
    catData.push(cat("kiko"));

    cout << catData.front() << endl;
    try {
        catData.push();
    } catch(simpleException &ex) {
        cout << ex.what() << endl;
    }

    cout << data.front() << endl;
    data.pop();
    cout << data.front() << endl;
    data.pop();
    cout << data.front() << endl;
    data.pop();
    cout << data.front() << endl;
    data.pop();
    try {
        cout << data.front() << endl;
        data.pop();
    } catch(simpleException &ex) {
        cout << ex.what() << endl;
    }
}

int main() {
    templateFunctionTest();
    templateContainerTest();

    return 0;
}
