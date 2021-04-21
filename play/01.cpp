#include <iostream>

using namespace std;

int main() {
    int i = 336;
    char c = 336;
    int j = c;
    long l = 10L + INT_MAX;
    int d = l;
    cout << c << " " << j << endl;
    cout << l << " " << d << endl;
    return 0;
}
