#include <iostream>

using namespace std;

int main() {
    string a, b;
    int n, cur, la, lb, i, j;
    short s[1001];

    cin >> n;
    j = 0;
    while (++j <= n) {
        cin >> a >> b;
        la = a.length();
        lb = b.length();
        i = 0;
        cur = 0;

        while (la > 0 || lb > 0 || cur > 0) {
            cur += la > 0 ? a[--la] - '0' : 0;
            cur += lb > 0 ? b[--lb] - '0' : 0;
            s[i] = cur % 10;
            cur /= 10;
            ++i;
        }

        cout << "Case " << j << ":" << endl << a << " + " << b << " = "; 

        while (i--) cout << s[i];
        cout << endl;
        if (j != n) cout << endl;
    }
    return 0;
}
