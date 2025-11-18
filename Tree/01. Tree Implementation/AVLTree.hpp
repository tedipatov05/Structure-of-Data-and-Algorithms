#pragma once
#include <algorithm>
#include <stdlib.h>

struct Node
{
	int value;
	Node* left;
	Node* right;
	int height;

	Node(int value)
	{
		this->value = value;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};

class AVLTree
{
private:

	Node* root;

	int height(Node* node);
	int getBalance(const Node* node);
	void updateHeight(Node* node);
	Node* rotateLeft(Node* node);
	Node* rotateRight(Node* node);
	Node* insert(Node* node, int value);
	Node* minValueNode(Node* node);
	Node* deleteNode(Node* node, int value);
	void inorder(Node* node) const;
	void preorder(Node* node) const;
	bool search(Node* node, int value);

public:
	AVLTree() = default;

	void insert(int value);
	void remove(int value);
	void preorder() const;
	void inorder() const;
	bool search(int value);

};

inline int AVLTree::height(Node* node)
{
	return node->height;
}

inline int AVLTree::getBalance(const Node* node)
{
	return node ? height(node->left) - height(node->right) : 0;
}

inline void AVLTree::updateHeight(Node* node)
{
	if (node)
	{
		node->height = 1 + std::max(height(node->left), height(node->right));
	}
}

inline Node* AVLTree::rotateLeft(Node* node)
{
	Node* y = node->right;
	Node* T2 = y->left;

	y->left = node;
	node->right = T2;

	updateHeight(node);
	updateHeight(y);

	return y;
}

inline Node* AVLTree::rotateRight(Node* node)
{
	Node* newRoot = node->left;
	Node* rightOldRoot = newRoot->right;

	newRoot->right = node;
	node->left = rightOldRoot;

	updateHeight(node);
	updateHeight(newRoot);

	return newRoot;
}

inline Node* AVLTree::insert(Node* node, int value)
{
	if (!node)
	{
		return new Node(value);
	}

	if (value > node->value)
	{
		node->right = insert(node->right, value);
	}
	else if (value < node->value)
	{
		node->left = insert(node->left, value);
	}
	else
	{
		return node;
	}

	updateHeight(node);

	int balance = getBalance(node);

	if (balance > 1 && value < node->left->value)
	{
		return rotateRight(node);
	}

	if (balance < -1 && value > node->right->value)
	{
		return rotateLeft(node);
	}

	if (balance > 1 && value > node->left->value)
	{
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}

	if (balance < -1 && value < node->right->value)
	{
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	return node;
}






