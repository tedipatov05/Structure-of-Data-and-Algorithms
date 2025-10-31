#pragma once
#include <exception>

template <typename T>
class SinglyLinkedList {
private:
	struct Node {
		T data;
		Node* next;
		Node(T val) : data(val), next(nullptr) {}
	};

	Node* head;
	Node* tail;
	size_t size;


public:

	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList<T>&);
	SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>&);
	~SinglyLinkedList();

	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
	void remove(const T&);
	bool contains(const T&) const;
	void print() const; // Optional: for debugging purposes
	void insert(const T&, size_t);
	size_t getSize() const;

	const T& front() const;
	const T& back() const;

private:
	void copyFrom(const SinglyLinkedList<T> other);
	void free();
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other) {
	copyFrom(other);
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	free();
}

template <typename T>
void SinglyLinkedList<T>::copyFrom(const SinglyLinkedList<T> other)
{
	Node* iter = other.head;
	this.size = other.size;
	while (iter != nullptr) {
		push_back(iter->data);
		iter = iter->next;
	}
}

template <typename T>
void SinglyLinkedList<T>::free()
{
	Node* iter = head;
	while (iter != nullptr) {
		Node* toDelete = iter;
		iter = iter->next;
		delete toDelete;
	}
	head = tail = nullptr;
	size = 0;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& data)
{
	Node* newNode = new Node(data);
	if (tail != nullptr)
	{
		tail->next = newNode;
		tail = tail->next;
	}
	else
	{
		head = tail = newNode;
	}
	size++;
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T& data)
{
	Node* newHead = new Node(data);
	if (!head)
	{
		head = tail = newHead;
	}
	else
	{
		newHead->next = head;
		head = newHead;
	}
	size++;
}

template <typename T>
void SinglyLinkedList<T>::pop_back()
{
	if (!head) {
		throw std::exception("List is empty");
	}

	if (head == tail)
	{
		pop_front();
		return;
	}

	Node* current = head;
	while (current->next != tail) {
		current = current->next;
	}

	Node* nodeToDelete = tail;
	tail = current;
	tail->next = nullptr;
	delete nodeToDelete;
	size--;
}

template <typename T>
void SinglyLinkedList<T>::pop_front()
{
	if (!head) {
		throw std::exception("List is empty");
	}
	Node* nodeToDelete = head;
	head = head->next;
	delete nodeToDelete;
	size--;
	if (!head) {
		tail = nullptr;
	}
}

template <typename T>
void SinglyLinkedList<T>::remove(const T& data)
{
	if (!head) {
		throw std::exception("List is empty");
	}

	if (head->data == data) {
		pop_front();
		return;
	}

	Node* prev = head;
	while (prev->next && prev->next->data != data) {
		prev = prev->next;
	}

	if (!prev->next) {
		return;
	}

	Node* toDelete = prev->next;
	prev->next = toDelete->next;

	if (toDelete == tail) {
		tail = prev;
	}

	delete toDelete;
	size--;
}

template <typename T>
void SinglyLinkedList<T>::insert(const T& data, size_t index)
{
	if (index > size) {
		throw std::exception("Index out of bounds");
	}
	if (index == 0) {
		push_front(data);
		return;
	}
	if (index == size) {
		push_back(data);
		return;
	}
	Node* newNode = new Node(data);
	Node* iter = head;
	for (size_t i = 0; i < index - 1; i++) {
		iter = iter->next;
	}
	newNode->next = iter->next;
	iter->next = newNode;
	size++;

}

template <typename T>
bool SinglyLinkedList<T>::contains(const T& data) const
{
	Node* iter = head;
	while (iter != nullptr) {
		if (iter->data == data) {
			return true;
		}
		iter = iter->next;
	}
	return false;
}

template <typename T>
void SinglyLinkedList<T>::print() const
{
	Node* iter = head;
	while (iter != nullptr) {
		std::cout << iter->data << " ";
		iter = iter->next;
	}
	std::cout << std::endl;
}

template <typename T>
size_t SinglyLinkedList<T>::getSize() const
{
	return size;
}

template <typename T>
const T& SinglyLinkedList<T>::front() const
{
	if (!head) {
		throw std::exception("List is empty");
	}
	return head->data;
}

template <typename T>
const T& SinglyLinkedList<T>::back() const
{
	if (!tail) {
		throw std::exception("List is empty");
	}
	return tail->data;
}






