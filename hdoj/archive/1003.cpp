#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, n, ti = 0, m;
    cin >> t;
    while (ti++ < t) {
        int sum = 0, ni = 0, mn = 0, mx = INT_MIN, pl = 0, pll = 0, pr = 0;
        cin >> n;
        while (ni++ < n) {
            cin >> m;
            sum += m;

            if (mx < sum - mn) {
                mx = sum - mn;
                pll = pl + 1;
                pr = ni;
            }

            if (mn > sum) {
                mn = sum;
                pl = ni;
            }
        }

        cout << "Case " << ti << ":" << endl;
        cout << mx << " " << pll << " " << pr << endl;
        if (ti < t) cout << endl;
    }
    return 0;
}
