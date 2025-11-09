
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

struct Node
{
	int value;
	Node* next;
	// Constructor with two arguments, one of which is default
	Node(int value, Node* next = nullptr) : value(value), next(next) {};
};

struct SinglyLinkedList
{
	Node* head, * tail;
	int size;

	SinglyLinkedList() :head(nullptr), tail(nullptr), size(0) {}; // Default constructor

	void addAtHead(int X); // Utility function for add 
	void addAtTail(int X); // Utility function for add 
	void add(int X, int pos);

	void remove(int pos);

	void reverse(); // Iterative

	Node* reverseNode(Node* node);

	Node* reverseRecursiveUtil(Node* head); // Utility function for recursive reverse function
	void reverseRecursive(); // Recursive

	bool isPalindrom();

	int count(int X);

	void removeAll(int X);

	void group(int start, int end);

	// Instead of print function
	friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list);
};



int main()
{
	size_t N, Q; std::cin >> N;

	int el(0), pos(0);

	for (size_t i = 0; i < N; i++)
	{
		SinglyLinkedList list;
		std::cin >> Q; std::cin.ignore();
		for (size_t i = 0; i < Q; i++)
		{

			std::string line; getline(std::cin, line);
			std::istringstream istr(line);

			std::string command; istr >> command;

			if (command == "add")
			{
				istr >> el >> pos;
				list.add(el, pos);
			}
			else if (command == "print")
			{
				std::cout << list;
			}
			else if (command == "remove")
			{
				istr >> pos;
				list.remove(pos);
			}
			else if (command == "remove_all")
			{
				istr >> el;
				list.removeAll(el);
			}
			else
			{
				int count(0);
				while (istr)
				{
					istr >> command;
					count++;
				}
				i += count - 1;
			}
		}
		std::cout << '\n';
	}
	return 0;
}

std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list)
{
	Node* traverse = list.head;
	while (traverse != nullptr)
	{
		os << traverse->value << '#';
		traverse = traverse->next;
	} //os << '\n';
	return os;
}

void SinglyLinkedList::addAtHead(int X)
{
	Node* newNode = new Node(X);
	if (head == nullptr) // tail will then also point to nullptr
	{
		head = tail = newNode;
	}
	else
	{
		Node* temp = head;
		newNode->next = temp;
		head = newNode;
	}
	size++;
}

Node* SinglyLinkedList::reverseNode(Node* head) {
	Node* prev = nullptr;
	Node* curr = head;
	while (curr != nullptr) {
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}


bool SinglyLinkedList::isPalindrom()
{
	Node* slow = head;
	Node* fast = head;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	Node* rev = reverseNode(slow);
	while (rev != nullptr) {
		if (head->value != rev->value) {
			return false;
		}
		head = head->next;
		rev = rev->next;
	}
	return true;
}



void SinglyLinkedList::addAtTail(int X)
{
	Node* newNode = new Node(X);
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

void SinglyLinkedList::add(int X, int pos)
{
	if (pos == 0) {
		addAtHead(X);
	}
	else if (pos < 0 || pos > size)
	{
		addAtTail(X);
		std::cout << "add_last";
	}
	else if (pos == size)
	{
		addAtTail(X);
	}
	else
	{
		Node* newNode = new Node(X);
		Node* traverse = head;
		for (int i = 1; i < pos; i++)
		{
			traverse = traverse->next;
		} // traverse points to (pos-1)th Node        
		Node* temp = traverse->next; // pos-th Node  :  traverse - newNode - temp
		traverse->next = newNode;
		newNode->next = temp;
		size++;
	}
}

void SinglyLinkedList::remove(int pos)
{
	if (pos < 0 || pos >= (int)size)
	{
		std::cout << "remove_failed";
	}
	else if (pos == 0)
	{
		Node* temp = head->next;
		delete head;
		head = temp;
		size--;
	}
	else
	{
		Node* traverse = head;
		for (int i = 0; i < pos - 1; i++)
		{
			traverse = traverse->next;
		} // traverseNode points to (pos-1)th Node
		Node* temp = traverse->next; // pos-th Node (node we want to remove)
		traverse->next = temp->next; // (pos+1)th Node
		if (temp->next == nullptr)
		{
			tail = traverse;
		}
		delete temp; // remove temp;
		size--;
	}
}


void SinglyLinkedList::removeAll(int target)
{
	while (head != nullptr && head->value == target) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	if (head == nullptr) {
		return;
	}

	Node* curr = head;
	while (curr->next != nullptr) {
		if (curr->next->value == target) {
			Node* temp = curr->next;
			curr->next = curr->next->next;
			delete temp;
		}
		else {
			curr = curr->next;
		}
	}


}

void SinglyLinkedList::group(int start, int end)
{
	if (start < 0 || start >= this->size ||
		end < 0 || end >= this->size ||
		start > end) {
		std::cout << "fail_grouping";
		return;
	}

	if (start == end) {
		return;
	}

	size_t sum = 0;
	Node* runner = this->head;
	Node* startNode = nullptr;

	for (int i = 0; i < start; i++) {
		startNode = runner;
		runner = runner->next;
	}

	for (int i = 0; i <= end - start; i++) {
		sum += runner->value;
		runner = runner->next;
	}

	Node* newNode = new Node(sum);
	this->size -= end - start;

	if (startNode == nullptr)
	{
		this->head = newNode;
	}
	else
	{
		startNode->next = newNode;
	}

	newNode->next = runner;
}

int SinglyLinkedList::count(int X)
{
	int counter = 0;
	Node* iter = head;
	while (iter) {
		if (iter->value == X) {
			counter++;
		}

		iter = iter->next;
	}
	return counter;
}
