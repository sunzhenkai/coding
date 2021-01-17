#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
    map<short, int> mp = {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };

    int v(short s) {
        switch (s) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
        }
        return -1;
    };
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i + 1 < s.length() && v(s[i]) < v(s[i+1])) {
                res -= v(s[i]);
            } else {
                res += v(s[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string inp;
    while (cin >> inp) {
        cout << s.romanToInt(inp) << endl;
    }
    return 0;
}
