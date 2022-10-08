/**
 * @file   023.cpp
 *
 * @brief  合并K个升序链表
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Thu Jan 21 22:51:53 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include "../template/utils.h"
#include "../template/leetcode.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeList(ListNode* a, ListNode* b) {
        if (a == nullptr) return b;
        else if (b == nullptr) return a;

        ListNode *head = a->val < b->val ? a : b;
        ListNode *res = head;

        if (a->val < b->val) a = a->next;
        else b = b->next;

        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                head->next = a;
                a = a->next;
            } else {
                head->next = b;
                b = b->next;
            }
            head = head->next;
        }

        if (a != nullptr) head->next = a;
        else head->next = b;
        return res;
    }

    ListNode* mergeLists(vector<ListNode*>& lists, int l, int r) {
        int mid = (l + r) / 2;
        if (l == r) return lists[l];
        else if (l + 1 == r) return mergeList(lists[l], lists[r]);
        else return mergeList(mergeLists(lists, l, mid), mergeLists(lists, mid+1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        return mergeLists(lists, 0, lists.size() - 1);
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<ListNode*> lns;
    while (n--) {
        ListNode *ln = readList();
        lns.push_back(ln);
    }
    printList(s.mergeKLists(lns));
    return 0;
}
