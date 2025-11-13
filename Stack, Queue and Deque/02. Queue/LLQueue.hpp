#pragma once
#include <list>

template<typename T>
class LLQueue {
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
void LLQueue<T>::push(const T& obj) {
	data.push_back(obj); 
}

template<typename T>
void LLQueue<T>::pop() {
	if (isEmpty()) {
		throw std::exception("Queue is empty");
	}
	data.pop_front();
}

template<typename T>
const T& LLQueue<T>::peek() const {
	if (isEmpty()) {
		throw std::exception("Queue is empty");
	}
	return data.front();
}

template<typename T>
bool LLQueue<T>::isEmpty() const {
	return data.size() == 0;
}

template<typename T>
size_t LLQueue<T>::getSize() const {
	return data.size();
}

template<typename T>
void LLQueue<T>::clear() {
	data.clear();
}