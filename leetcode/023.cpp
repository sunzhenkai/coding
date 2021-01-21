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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* mergeList(ListNode* a, ListNode* b) {
        if (a == null) return b;
        else if (b == null) return a;

        ListNode* head = a->val > b->val ? b : a;
        ListNode* res = head;

        while (a != null && b != null) {
            if (a->val > b->val) {
                head->next = b;
                b = b->next;
            } else {
                head->next = a;
                a = a->next;
            }
            head = head->next;
        }
        if (a != null) head->next = a;
        else head->next = b;
        return res;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeList(lists[0], lists[1]);
    }
};

int main() {
    // TODO: Test Read List
    return 0;
}
