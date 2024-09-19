#include <iostream>

using namespace std;

int main() {
    int n, res;
    while (cin >> n) {
        res = n % 2 == 0 ? n / 2 * (1 + n) : (1 + n) / 2 * n;
        cout << res << endl << endl;
    }
    return 0;
}
