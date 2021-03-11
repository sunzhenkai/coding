#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    Node *n;
    Node *p;
    int k, v;
};

class LRU {
private:
    int capacity;
    int size;
    Node *head = nullptr;
    Node *tail = nullptr;
    unordered_map<int, Node*> data;
public:
    LRU(int cp) : capacity(cp), size(0) {} 

    void put(int k, int v);
    int get(int k);
    
    void reduce();
    void addToHead(Node *node);
    void moveToHead(Node *node);

    void show();
};

void LRU::show() {
    Node *stt = head;
    while (stt != nullptr) {
        cout << stt->k << " ";
        stt = stt->n;
    }
    cout << endl;
}

void LRU::reduce() {
    Node *t = tail;
    tail->p->n = nullptr;
    tail = tail->p;
    data.erase(t->k);
    --size;
}

void LRU::put(int k, int v) {
    auto it = data.find(k);
    if (it == data.end()) {
        if (size >= capacity) {
            reduce();
        }

        Node *nd = new Node();
        nd->v = v;
        nd->k = k;
        data[k] = nd;
        addToHead(nd);
        ++size;
    } else {
        Node *nd = data[k];
        nd->v = v;
        moveToHead(nd);
    }
}

int LRU::get(int k) {
    auto it = data.find(k);
    if (it == data.end()) {
        return -1;
    }
    moveToHead(it->second);
    return it->second->v;
}

void LRU::addToHead(Node *node) {
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        node->p = nullptr;
        head->p = node;
        node->n = head;
        head = node;
    }
}

void LRU::moveToHead(Node *node) {
    if (node->p == nullptr) {
        return;
    } else {
        if (node->n != nullptr) {
            node->n->p = node->p;
        }
        node->p->n = node->n;
        addToHead(node);
    }
}

int main() {
    string op;
    int v, k;
    LRU lru(5);
    while (cin >> op) {
        if (op == "get") {
            cin >> k;
            cout << lru.get(k) << endl;
        } else if (op == "show") {
            lru.show();
        } else {
            cin >> k >> v;
            lru.put(k, v);
        }
    }
    return 0;
}
