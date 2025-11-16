#pragma once
#include <iostream>
#include <queue>

struct Node
{
	Node* left;
	Node* right;
	int value;

	Node() : left(nullptr), right(nullptr), value(0) {}
};

class Tree
{
public:

	void insertNode(int value);
	void deleteNode(int value);
	bool search(int value);
	void inorder();
	void preorder();
	void postorder();
	void bfsTree();
	bool isValidBST();
	int height();

	// TODO:
	void kthSmallestHelper(Node* node, int& k, int& result);
	Node* lcaHelper(Node* node, int n1, int n2);
	Node* successorHelper(Node* node, int val, Node*& succ);
	Node* predecessorHelper(Node* node, int val, Node*& pred);



private:

	Node* root;

	Node* insertHelper(Node* node, int value);
	Node* findMin(Node* node);
	Node* findMax(Node* node);
	Node* deleteHelper(Node* node, int value);
	bool searchHelper(Node* node, int value);
	void inorderHelper(Node* node);
	void preorderHelper(Node* node);
	void postorderHelper(Node* node);
	int heightHelper(Node* node);
	bool isValidBSTHelper(Node* node, long minVal, long maxVal);
	void bfsTraversal();

	// TODO:
	int findLCA(int n1, int n2);
	int findKSmallest(int k);
	int findPredecessor(int value);
	int findSuccessor(int value);
};

inline Node* Tree::insertHelper(Node* node, int value)
{
	if (node == nullptr)
	{
		return new Node(value);
	}

	if (value < node->value)
	{
		node->left = insertHelper(node->left, value);
	}
	else if (value > node->value)
	{
		node->right = insertHelper(node->right, value);
	}

	return node;
}

inline Node* Tree::findMin(Node* node)
{
	while (node && node->left != nullptr) {
		node = node->left;
	}
	return node;
}

inline Node* Tree::findMax(Node* node)
{
	while (node && node->right)
	{
		node = node->right;
	}
	return node;
}


inline Node* Tree::deleteHelper(Node* node, int value)
{
	if (node == nullptr)
	{
		return node;
	}

	if (value < node->value)
	{
		node->left = deleteHelper(node->left, value);
	}
	else if (value > node->value)
	{
		node->right = deleteHelper(node->right, value);
	}
	else
	{
		if (!node->left && !node->right) {
			return nullptr;
		}
		if (!node->left)
		{
			return node->right;
		}

		if (!node->right)
		{
			return node->left;
		}

		Node* min = findMin(node->right);
		node->value = min->value;
		node->right = deleteHelper(node->right, min->value);

	}

	return node;
}

inline bool Tree::searchHelper(Node* node, int value)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (node->value == value)
	{
		return true;
	}

	if (value < node->value)
	{
		return searchHelper(node->left, value);
	}

	return searchHelper(node->right, value);
}

inline void Tree::inorderHelper(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	inorderHelper(node->left);
	std::cout << node->value << " ";
	inorderHelper(node->right);
}

inline void Tree::preorderHelper(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	std::cout << node->value << " ";
	preorderHelper(node->left);
	preorderHelper(node->right);
}

inline void Tree::postorderHelper(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	postorderHelper(node->left);
	postorderHelper(node->right);
	std::cout << node->value << std::endl;
}

inline int Tree::heightHelper(Node* node)
{
	if (node == nullptr)
	{
		return -1;
	}

	return 1 + std::max(heightHelper(node->left), heightHelper(node->right));
}

inline bool Tree::isValidBSTHelper(Node* node, long minVal, long maxVal)
{
	if (node == nullptr)
	{
		return true;
	}

	if (node->value <= minVal || node->value >= maxVal)
	{
		return false;
	}

	return isValidBSTHelper(node->left, minVal, node->value) &&
		isValidBSTHelper(node->right, node->value, maxVal);
}

inline void Tree::insertNode(int value)
{
	root = insertHelper(root, value);
}

inline void Tree::deleteNode(int value)
{
	root = deleteHelper(root, value);
}

inline void Tree::inorder()
{
	inorderHelper(root);
}

inline void Tree::postorder()
{
	postorderHelper(root);
}

inline void Tree::preorder()
{
	preorderHelper(root);
}

inline bool Tree::search(int value)
{
	return searchHelper(root, value);
}

inline int Tree::height()
{
	return heightHelper(root);
}

inline bool Tree::isValidBST()
{
	return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

inline void Tree::bfsTraversal()
{
	std::queue<Node*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		Node* curr = queue.front();
		queue.pop();

		std::cout << curr->value << " ";

		if (curr->left)
		{
			queue.push(curr->left);
		}

		if (curr->right)
		{
			queue.push(curr->right);
		}
	}

	std::cout << std::endl;
}


// TODO:

inline Node* Tree::lcaHelper(Node* node, int n1, int n2)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->value > n1 && node->value > n2) {
		return lcaHelper(node->left, n1, n2);
	}
	if (node->value < n1 && node->value < n2) {
		return lcaHelper(node->right, n1, n2);
	}
	return node;
}

inline int Tree::findLCA(int n1, int n2)
{
	Node* lca = lcaHelper(root, n1, n2);
	return lca ? lca->value : -1;
}

inline Node* Tree::predecessorHelper(Node* node, int val, Node*& pred)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->value == val)
	{
		if (node->left != nullptr)
		{
			return findMax(node->left);
		}

		return pred;
	}

	if (val < node->value)
	{
		return predecessorHelper(node->left, val, pred);
	}
	else
	{
		pred = node;
		return predecessorHelper(node->right, val, pred);
	}
}

inline int Tree::findPredecessor(int value)
{
	Node* pred = nullptr;
	Node* result = predecessorHelper(root, value, pred);
	return result ? result->value : -1;

}

inline Node* Tree::successorHelper(Node* node, int val, Node*& succ)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->value == val)
	{
		if (node->right != nullptr)
		{
			return findMin(node->right);
		}

		return succ;
	}

	if (val < node->value)
	{
		succ = node;
		return successorHelper(node->left, val, succ);
	} else
	{
		return successorHelper(node->right, val, succ);
	}
}



















