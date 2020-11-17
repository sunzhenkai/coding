#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main() {
    int a = 1, b;
    bool isFirst = true;
    while (cin >> b) {
        if (!isFirst) {
//            cout << endl;
        } else {
            isFirst = false;
        }
        int sum = a + b;
        int cnt = b - a + 1;
        if (sum % 2 == 0)
            sum /= 2;
        else
            cnt /= 2;
        cout << sum * cnt << endl << endl;
    }

    return 0;
}
