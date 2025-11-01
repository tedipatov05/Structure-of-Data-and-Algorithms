#pragma once
#include <exception>
#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
	struct Node {
		T data;
		Node* prev;
		Node* next;
		Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
	};
	Node* head;
	Node* tail;
	size_t size;
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<T>&);
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
	~DoublyLinkedList();

	void push_front(const T& value);
	void push_back(const T& value);
	void pop_front();
	void pop_back();
	bool contains(const T& value) const;

	const T& front() const;
	const T& back() const;
	size_t getLength() const;

	void print() const;

private:
	void copyFrom(const DoublyLinkedList<T>&);
	void free();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) : head(nullptr), tail(nullptr), size(0) {
	copyFrom(other);
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	free();
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value)
{
	Node* newNode = new Node(value);

	if (!head && !tail)
	{
		head = tail = newNode;
		size++;
		return;
	}

	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	size++;
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value)
{
	Node* newNode = new Node(value);
	if (!head)
	{
		head = tail = newNode;
		size++;
		return;
	}

	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	size++;
}

template <typename T>
void DoublyLinkedList<T>::copyFrom(const DoublyLinkedList<T>& other)
{
	Node* iter = other.head;
	while (iter)
	{
		push_back(iter->value);
		iter = iter->next;
	}
}

template <typename T>
void DoublyLinkedList<T>::free()
{
	Node* iter = head;

	while (iter)
	{
		Node* next = iter->next;
		delete iter;
		iter = next;
	}

	size = 0;
	head = tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::pop_front()
{
	if (!head)
	{
		throw std::exception("List is empty");
	}

	Node* nodeToDelete = head;
	if (head == tail)
	{
		head = tail = nullptr;
	}
	else
	{
		head = head->next;
		head->prev = nullptr;
	}

	delete nodeToDelete;
	size--;
}

template <typename T>
void DoublyLinkedList<T>::pop_back()
{
	if (!tail)
	{
		throw std::exception("List is empty");
	}

	Node* nodeToDelete = tail;
	if (head == tail)
	{
		head = tail = nullptr;
	}
	else
	{
		Node* prev = nodeToDelete->prev;
		prev->next = nullptr;
		nodeToDelete->prev = nullptr;
		head = prev;
		delete nodeToDelete;
	}

	size--;
}

template <typename T>
const T& DoublyLinkedList<T>::back() const
{
	return tail->data;
}

template <typename T>
bool DoublyLinkedList<T>::contains(const T& value) const
{
	Node* current = head;
	while (current)
	{
		if (current->data == value)
		{
			return true;
		}
		current = current->next;
	}

	return false;
}

template <typename T>
const T& DoublyLinkedList<T>::front() const
{
	return head->data;
}

template <typename T>
size_t DoublyLinkedList<T>::getLength() const
{
	return size;
}

template <typename T>
void DoublyLinkedList<T>::print() const
{
	Node* current = head;
	while (current)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
}











