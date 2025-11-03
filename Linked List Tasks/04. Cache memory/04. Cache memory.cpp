// 04. Cache memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node* hashNext;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr), hashNext(nullptr) {}
};

class LRUCache {
private:
    static const int HASH_SIZE = 100003;
    int capacity;
    int burnoutInterval;
    int requestCount;
    int size;
    Node* head;
    Node* tail;
    Node* hashTable[HASH_SIZE];

    int hash(int key) {
        return ((key % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;
    }

    void removeNode(Node* node) {
        if (node->prev) {
            node->prev->next = node->next;
        }
        else {
            head = node->next;
        }

        if (node->next) {
            node->next->prev = node->prev;
        }
        else {
            tail = node->prev;
        }
    }

    void addToFront(Node* node) {
        node->next = head;
        node->prev = nullptr;

        if (head) {
            head->prev = node;
        }
        head = node;

        if (!tail) {
            tail = node;
        }
    }

    void moveToFront(Node* node) {
        if (node == head) return;

        removeNode(node);
        addToFront(node);
    }

    void addToHash(Node* node) {
        int h = hash(node->key);
        node->hashNext = hashTable[h];
        hashTable[h] = node;
    }

    void removeFromHash(int key) {
        int h = hash(key);
        Node* current = hashTable[h];
        Node* prev = nullptr;

        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->hashNext = current->hashNext;
                }
                else {
                    hashTable[h] = current->hashNext;
                }
                return;
            }
            prev = current;
            current = current->hashNext;
        }
    }

    Node* findNode(int key) {
        int h = hash(key);
        Node* current = hashTable[h];

        while (current) {
            if (current->key == key) {
                return current;
            }
            current = current->hashNext;
        }
        return nullptr;
    }

    void removeLRU() {
        if (tail) {
            Node* toRemove = tail;
            removeNode(toRemove);
            removeFromHash(toRemove->key);
            delete toRemove;
            size--;
        }
    }

    void checkBurnout() {
        requestCount++;
        if (requestCount % burnoutInterval == 0) {
            removeLRU();
        }
    }

public:
    LRUCache(int cap, int burnout) : capacity(cap), burnoutInterval(burnout), requestCount(0), size(0), head(nullptr), tail(nullptr) {
        for (int i = 0; i < HASH_SIZE; i++) {
            hashTable[i] = nullptr;
        }
    }

    void put(int key, int value) {
        Node* existing = findNode(key);

        if (existing) {
            existing->value = value;
            moveToFront(existing);
        }
        else {
            if (size == capacity) {
                removeLRU();
            }

            Node* newNode = new Node(key, value);
            addToFront(newNode);
            addToHash(newNode);
            size++;
        }

        checkBurnout();
    }

    int get(int key) {
        Node* node = findNode(key);
        int result = -1;

        if (node) {
            moveToFront(node);
            result = node->value;
        }

        checkBurnout();

        return result;
    }

    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    // for Hacker rank purpose 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int N, Q, K;
	cin >> N >> Q >> K;

    LRUCache cache(N, K);

    for (int i = 0; i < Q; i++) {
        string operation;
        cin >> operation;

        if (operation == "put") {
            int x, y;
            cin >> x >> y;
            cache.put(x, y);
        }
        else if (operation == "get") {
            int x;
            cin >> x;
            cout << cache.get(x) << "\n";
        }
    }

    return 0;
}