/**
 * @file   06.cpp
 *
 * @brief  打印链表
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Tue Apr 20 22:52:46 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = res.size() - 1;
        while (i < j) swap(res[i++], res[j--]);
        return res;
    }
};

int main() {
    return 0;
}
