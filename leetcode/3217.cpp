/**
 * @file   3217.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sat Nov  1 06:44:25 AM CST 2025
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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    std::vector<bool> flags(1e5 + 1, 0);
    for (auto i : nums) flags[i] = 1;
    ListNode dummy(0, head);
    ListNode *cur = dummy.next, *last = &dummy;
    while (cur != nullptr) {
      bool is_delete = flags[cur->val];
      last->next = is_delete ? cur->next : cur;
      last = is_delete ? last : cur;
      cur = cur->next;
    }
    return dummy.next;
  }

  ListNode* modifiedListV1(vector<int>& nums, ListNode* head) {
    std::unordered_map<int, int> m;
    for (auto i : nums) m[i] = 1;
    ListNode dummy(0, head);
    ListNode *cur = dummy.next, *last = &dummy;
    while (cur != nullptr) {
      bool is_delete = m.find(cur->val) != m.end();

      last->next = is_delete ? cur->next : cur;
      last = is_delete ? last : cur;
      cur = cur->next;
    }
    return dummy.next;
  }
};

int main() { return 0; }
