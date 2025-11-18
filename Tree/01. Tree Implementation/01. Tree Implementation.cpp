// 01. Tree Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Helper function for recursive DFS
    void dfsInorderRecursive(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        dfsInorderRecursive(node->left, result);
        result.push_back(node->data);
        dfsInorderRecursive(node->right, result);
    }

    void dfsPreorderRecursive(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        result.push_back(node->data);
        dfsPreorderRecursive(node->left, result);
        dfsPreorderRecursive(node->right, result);
    }

    void dfsPostorderRecursive(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        dfsPostorderRecursive(node->left, result);
        dfsPostorderRecursive(node->right, result);
        result.push_back(node->data);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
            return;
        }

        Node* curr = root;
        while (true) {
            if (val < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = new Node(val);
                    break;
                }
                curr = curr->left;
            }
            else {
                if (curr->right == nullptr) {
                    curr->right = new Node(val);
                    break;
                }
                curr = curr->right;
            }
        }
    }

    // BFS - Iterative (Level Order Traversal)
    vector<int> bfsIterative() {
        vector<int> result;
        if (root == nullptr) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            result.push_back(curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        return result;
    }

    // BFS - Recursive (using helper with queue)
    vector<int> bfsRecursive() {
        vector<int> result;
        queue<Node*> q;
        if (root) q.push(root);
        bfsRecursiveHelper(q, result);
        return result;
    }

private:
    void bfsRecursiveHelper(queue<Node*>& q, vector<int>& result) {
        if (q.empty()) return;

        Node* curr = q.front();
        q.pop();
        result.push_back(curr->data);

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);

        bfsRecursiveHelper(q, result);
    }

public:
    // DFS - Iterative Inorder
    vector<int> dfsInorderIterative() {
        vector<int> result;
        stack<Node*> s;
        Node* curr = root;

        while (curr != nullptr || !s.empty()) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            result.push_back(curr->data);
            curr = curr->right;
        }

        return result;
    }

    // DFS - Iterative Preorder
    vector<int> dfsPreorderIterative() {
        vector<int> result;
        if (root == nullptr) return result;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* curr = s.top();
            s.pop();
            result.push_back(curr->data);

            if (curr->right) s.push(curr->right);
            if (curr->left) s.push(curr->left);
        }

        return result;
    }

    // DFS - Iterative Postorder
    vector<int> dfsPostorderIterative() {
        vector<int> result;
        if (root == nullptr) return result;

        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* curr = s1.top();
            s1.pop();
            s2.push(curr);

            if (curr->left) s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }

        while (!s2.empty()) {
            result.push_back(s2.top()->data);
            s2.pop();
        }

        return result;
    }

    // DFS - Recursive Inorder
    vector<int> dfsInorderRecursive() {
        vector<int> result;
        dfsInorderRecursive(root, result);
        return result;
    }

    // DFS - Recursive Preorder
    vector<int> dfsPreorderRecursive() {
        vector<int> result;
        dfsPreorderRecursive(root, result);
        return result;
    }

    // DFS - Recursive Postorder
    vector<int> dfsPostorderRecursive() {
        vector<int> result;
        dfsPostorderRecursive(root, result);
        return result;
    }
};

void printVector(const vector<int>& v, const string& label) {
    cout << label << ": ";
    for (int val : v) cout << val << " ";
    cout << endl;
}

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "BST Structure:\n";
    cout << "       50\n";
    cout << "      /  \\\n";
    cout << "    30    70\n";
    cout << "   /  \\  /  \\\n";
    cout << "  20  40 60  80\n\n";

    printVector(tree.bfsIterative(), "BFS Iterative");
    printVector(tree.bfsRecursive(), "BFS Recursive");

    cout << "\nDFS Traversals:\n";
    printVector(tree.dfsInorderIterative(), "Inorder Iterative");
    printVector(tree.dfsInorderRecursive(), "Inorder Recursive");

    printVector(tree.dfsPreorderIterative(), "Preorder Iterative");
    printVector(tree.dfsPreorderRecursive(), "Preorder Recursive");

    printVector(tree.dfsPostorderIterative(), "Postorder Iterative");
    printVector(tree.dfsPostorderRecursive(), "Postorder Recursive");

    return 0;
}