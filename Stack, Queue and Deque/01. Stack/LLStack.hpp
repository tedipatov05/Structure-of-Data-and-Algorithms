#pragma once
#include <list>

template<typename T>
class LLStack {
private:

	std::list<T> data;
public:
	void push(const T& obj);
	void pop();
	const T& peek() const;

	bool isEmpty() const;
	size_t getSize() const;
	void clear();
};

template<typename T>
void LLStack<T>::push(const T& obj) {
	data.push_back(obj);
}

template<typename T>
void LLStack<T>::pop() {
	if (isEmpty()) {
		throw std::exception("Stack is empty");
	}
	data.pop_back();
}

template<typename T>
const T& LLStack<T>::peek() const {
	if (isEmpty()) {
		throw std::exception("Stack is empty");
	}

	return data.back();
}

template<typename T>
bool LLStack<T>::isEmpty() const {
	return data.size() == 0;
}

template<typename T>
size_t LLStack<T>::getSize() const {
	return data.size();
}

template<typename T>
void LLStack<T>::clear() {
	this.data.clear();
}