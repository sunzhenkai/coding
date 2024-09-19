/**
 * @brief  K 个一组翻转链表
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Fri Jan 22 20:09:09 CST 2021
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) 
            return head;

        int i;
        ListNode *l = head, *r = head, *res = nullptr, *nxt, *lst = nullptr, *lt = nullptr;
        while (r != nullptr) {
            for (i = 0; i < k && r != nullptr; ++i) 
                r = r->next;

            if (i == k) {
                ListNode* hd = l;
                while (l != r) {
                    nxt = l->next;
                    l->next = lst;
                    lst = l;
                    l = nxt;
                }
                if (lt != nullptr) lt->next = lst;
                lt = hd;
                hd->next = nullptr;
                if (res == nullptr)
                    res = lst;
            } else if (res == nullptr) {
                return head;
            } else {
                lt->next = l;
                return res;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int n, m;
    cin >> n;
    while (n--) {
        cin >> m;
        ListNode *ln = readList();
        printList(s.reverseKGroup(ln, m));
    }
    return 0;
}
