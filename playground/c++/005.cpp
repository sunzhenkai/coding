#include <iostream>

using namespace std;

class A {
public:
    static A Instance() {
        static A _a;
        return _a;
    }

private:
    A() {
        cout << "create A" << endl;
    }
}

int main() {
    A::instance(); 
    A::instance(); 
    A::instance(); 
    A::instance(); 
    A::instance(); 
    A::instance(); 
    return 0;
}
