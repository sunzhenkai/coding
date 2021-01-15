/**
 * @file   1004.cpp
 *
 * @brief  Let the Balloon Rise
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Thu Jan 14 23:52:59 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    while (cin >> n && n > 0) {
        map<string, int> m;
        string ts, res;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> ts;
            if (m.find(ts) != m.end()) m[ts] = m[ts] + 1;
            else m[ts] = 1;

            if (mx < m[ts]) {
                mx = m[ts];
                res = ts;
            }
        }
        cout << res << endl;
    }
    return 0;
}
