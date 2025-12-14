#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>

template <typename T>
class Heap
{
private:
	std::vector<T> heap;
	std::function<bool(const T&, const T&)> compare;

	int parent(int i) const {
		return (i - 1) / 2;
	}
	int leftChild(int i) const {
		return 2 * i + 1;
	}
	int rightChild(int i) const {
		return 2 * i + 2;
	}
	void swap(int i, int j) {
		T temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}

	void heapifyUp(int index) {
		while (index > 0) {
			int parentIndex = parent(index);
			if (compare(heap[index], heap[parentIndex])) {
				swap(index, parentIndex);
				index = parentIndex;
			}
			else {
				break;
			}
		}
	}

	void heapifyDown(int index) {
		size_t size = heap.size();
		while (true) {
			int target = index;
			int left = leftChild(index);
			int right = rightChild(index);

			if (left < size && compare(heap[left], heap[target])) {
				target = left;
			}
			if (right < size && compare(heap[right], heap[target])) {
				target = right;
			}

			if (target != index) {
				swap(index, target);
				index = target;
			}
			else {
				break;
			}
		}
	}

public:
	Heap(bool isMinHeap) {
		if (isMinHeap) {
			compare = [](const T& a, const T& b) { return a < b; };
		}
		else {
			compare = [](const T& a, const T& b) { return a > b; };
		}
	}

	Heap(std::function<bool(const T&, const T&)> comp) : compare(comp) {}

	void insert(const T& value) {
		heap.push_back(value);
		heapifyUp(heap.size() - 1);
	}

	T extract() {
		if (heap.empty()) {
			throw std::out_of_range("out of range. the collection is empty");
		}

		if (heap.size() == 1) {
			T root = heap.front();
			heap.pop_back();
			return root;
		}

		T root = heap.front();
		heap[0] = heap.back();
		heapifyDown(0);
		return root;
	}

	T peek() const {
		if (heap.empty())
		{
			throw std::out_of_range("out of range. the collection is empty");
		}

		return heap.front();
	}

	int size() const
	{
		return heap.size();
	}

	bool empty() const
	{
		return heap.empty();
	}

	void buildHeap(const std::vector<T>& arr)
	{
		heap = arr;
		for (int i = heap.size() / 2 - 1; i >= 0; i--) {
			heapifyDown(i);
		}
	}
};