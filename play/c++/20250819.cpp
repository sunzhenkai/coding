#include <iostream>

struct Node {
  int val;
  Node *next;
};

void SolveV1(Node *head) {
  // 1. count
  int count = 0;
  Node *t_head = head;
  while (t_head) {
    count++;
    t_head = t_head->next;
  }

  // 2. mid & reverse
  int mid = count / 2;
  Node *t_pre = nullptr;
  t_head = head;
  for (int i = 0; i < count; ++i) {
    Node *t_head_next = t_head->next;
    // 调转方向
    if (i > mid) {
      t_head->next = t_pre;
    }
    t_pre = t_head;
    t_head = t_head_next;
  }

  // 3. 交换
  Node *left = head, *right = t_pre;
  while (true) {
    Node *left_next = left->next;
    Node *right_next = right->next;
    if (left_next == right || left == right) {
      break;
    }

    left->next = right;
    right->next = left_next;
    left = left_next;
    right = right_next;
  }
  left->next = nullptr;
}

void SolveV2(Node *head) {
  // 1. 统计数量
  int count = 0;
  {
    Node *t_head = head;
    while (t_head != nullptr) {
      count++;
      t_head = t_head->next;
    }
  }

  // 2. 切断并转换方向
  Node *left = head, *right = nullptr;
  {
    int mid = count / 2;
    Node *t_head = head, *t_pre = nullptr;
    for (int i = 0; i < count; ++i) {
      Node *t_head_next = t_head->next;
      if (i < mid) {
      } else if (i == mid) {
        t_head->next = nullptr;
      } else {
        t_head->next = t_pre;
      }

      t_pre = t_head;
      t_head = t_head_next;
    }
    right = t_pre;
  }

  // 3. 合并
  while (left != nullptr || right != nullptr) {
    Node *left_next = left->next;
    Node *right_next = right->next;

    left->next = right;
    if (right != nullptr) {
      right->next = left_next;
    }
    left = left_next;
    right = right_next;
  }
}

void Display(Node *root) {
  while (root != nullptr) {
    std::cout << root->val << " ";
    root = root->next;
  }
  std::cout << std::endl;
}

int main() {
  Node e{1, nullptr}, d{2, &e}, c{3, &d}, b{4, &c}, a{5, &b};
  Display(&a);
  // SolveV1(&a);
  SolveV2(&a);
  Display(&a);
  return 0;
}
