#include <iostream>

using namespace std;

int main() {
    int i[] = {1, 2, 3};
    for (auto &d : i) {
        cout << d << endl;
    }

    int j[][1] = {{1}, {2}, {3}};
    for (auto &k : j) {
        for (auto &l : k) {
            cout << l << endl;
        }
    }
    return 0;
}
