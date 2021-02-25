#include <iostream>

using namespace std;

class A {
public:
    A& operator=(const A&) = delete;
};

int main() {
    A a, b;
    a = b;
    return 0;
}
