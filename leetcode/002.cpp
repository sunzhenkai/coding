/**
 * @file   002.cpp
 * @brief  
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Wed Oct  1 05:43:26 AM CST 2025
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode head;
      ListNode *root = &head;
      int sm{0};
      while (l1 != nullptr || l2 != nullptr || sm > 0) {
        ListNode* nn = new ListNode(0, nullptr);
        if (l1) {
          sm += l1->val;
          l1 = l1->next;
        }
        if (l2) {
          sm += l2->val;
          l2 = l2->next;
        }

        nn->val = sm % 10;
        sm = sm / 10;

        root->next = nn;
        root = nn;
      }
      return head.next;
    }
};

int main() { return 0; }
