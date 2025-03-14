#include <fstream>
#include <iostream>
#include <string>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ListNode() : val(0), next(nullptr) {}
};

ListNode *readList(std::string &f) {
  ListNode *head = nullptr, *cur = nullptr;
  std::ifstream in(f);
  int number;
  while (in >> number) {
    ListNode *nn = new ListNode(number);
    if (head == nullptr)
      head = cur = nn;
    else {
      cur->next = nn;
      cur = nn;
    }
  }
  return head;
}

void printList(ListNode *head) {
  while (head != nullptr) {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

ListNode *readList() {
  ListNode *head = nullptr, *cur = nullptr;
  int n, v;
  std::cin >> n;
  while (n--) {
    std::cin >> v;
    ListNode *nn = new ListNode(v);
    if (head == nullptr)
      head = cur = nn;
    else {
      cur->next = nn;
      cur = nn;
    }
  }
  return head;
}
