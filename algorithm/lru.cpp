/**
 * @file   lru.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sat 21 Sep 2024 09:12:28 AM CST
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//! @brief: double linked list node
struct Node {
  int value;
  Node *next{nullptr}, *prev{nullptr};
  Node(int v) : value(v) {}
};

//! @brief: lru cache
class LruCache {
 private:
  void _add(Node *node) {
    auto next = head->next;
    head->next = node;
    node->next = next;
    node->prev = head;
    next->prev = node;
  }

  void _remove(Node *node) {
    auto next = node->next;
    auto prev = node->prev;
    prev->next = next;
    next->prev = prev;
    node->next = nullptr;
    node->prev = nullptr;
  }
  void _touch(Node *node) {
    _remove(node);
    _add(node);
  }

 public:
  LruCache(int capacity) : capacity(capacity) {
    head = new Node(0);
    tail = new Node(0);
    head->next = tail;
    tail->prev = head;
  }

  ~LruCache() {
    while (head != nullptr) {
      auto next = head->next;
      delete head;
      head = next;
    }
  }

  void Put(int k, int v) {
    auto it = store.find(k);
    if (it == store.end()) {
      if (store.size() >= capacity) {
        auto latest = tail->prev;
        _remove(latest);
        delete latest;
      }
      Node *node = new Node(v);
      _add(node);
      store[k] = node;
    } else {
      it->second->value = v;
      _touch(it->second);
    }
  }

  void Get(int k, int &v) {
    auto it = store.find(k);
    if (it != store.end()) {
      v = it->second->value;
      _touch(it->second);
    }
  }

  int Head() { return head->next->value; }

  void Display() {
    auto *t = head;
    while (t != nullptr) {
      t = t->next;
    }
    std::cout << std::endl;
  }

 private:
  std::unordered_map<int, Node *> store;
  int capacity;
  Node *head{nullptr}, *tail{nullptr};
};

int main() {
  LruCache lru(10);
  lru.Put(1, 1);
  lru.Put(2, 2);
  lru.Put(3, 3);
  std::cout << "HEAD: " << lru.Head() << std::endl;
  // lru.Display();

  int value = 0;
  lru.Get(1, value);
  std::cout << "HEAD: " << lru.Head() << std::endl;
  std::cout << value << std::endl;
  return 0;
}
