/**
 * @file   030.cpp
 *
 * @brief  串联所有单词的子串
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sat Jan 23 12:49:27 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include "../template/utils.h"
#include "../template/leetcode.h"

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;

        if (s.empty() || words.empty())
            return res;

        // unique words
        map<string, int> rpt;
        for (int i = 0; i < words.size(); ++i) {
            auto it = rpt.find(words[i]);
            if (it != rpt.end()) {
                it->second += 1;
            } else {
                rpt[words[i]] = 1;
            }
        }

        vector<string> wds;
        vector<int> wrp;
        for (auto &entry : rpt) {
            wds.push_back(entry.first);
            wrp.push_back(entry.second);
        }

        int sl = s.size(), wl = wds[0].size();
        int v[sl];
        for (int i = s.size() - wl; i >= 0; --i) {
            v[i] = -1;
            for (int j = 0; j < wds.size(); ++j) {
                if (s.compare(i, wl, wds[j]) == 0)
                    v[i] = j;
            }
        }
        
        int ed = sl - wl * words.size();
        for (int i = 0, j; i <= ed; ++i) {
            vector<int> trp = wrp;
            bool flag = true;
            for (j = 0; j < words.size(); ++j) {
                int p = i + j * wl;
                if (p >= sl || v[p] < 0 || --trp[v[p]] < 0) {
                    flag = false;
                    break;
                }
            }

            if (flag && j == words.size())
                res.push_back(i);
        }
        return res;
    }
};

int main() {
    int m;
    cin >> m;
    while (m--) {
        string s, v;
        vector<string> vs;
        cin >> s;
        int n;
        cin >> n;
        while (n--) {
            cin >> v;
            vs.push_back(v);
        }
        Solution sl;
        pV(sl.findSubstring(s, vs));
    }
    return 0;
}
