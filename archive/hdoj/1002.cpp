/**
 * @file   1002.cpp
 *
 * @brief  A + B Problem II
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Tue Apr 27 19:13:34 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, i(0);
    string a, b;

    cin >> n;
    while (i++ < n) {
        if (i > 1) cout << endl;
        cout << "Case " << i << ":" << endl;
        cin >> a >> b;
        
        string res("");
        int la(a.length()-1), lb(b.length()-1);
        int sum(0);
        while (la >= 0 || lb >= 0 || sum > 0) {
            if (la >= 0) sum += a[la--] - '0';
            if (lb >= 0) sum += b[lb--] - '0';
            res = (char)('0' + sum % 10) + res;
            sum /= 10;
        }

        cout << a << " + " << b << " = " << res << endl;
    }
    return 0;
}
