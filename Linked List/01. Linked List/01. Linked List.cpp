// 01. Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SinglyLinkedList.hpp"

using namespace std;


int main()
{
	SinglyLinkedList<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		list.push_back(5);
	
		list.print();
	
		list.pop_front();
		list.print();
	
		list.pop_back();
		list.print();
	
		list.insert(10, 2);
		list.print();
	
		list.remove(1);
		list.print();
	
		std::cout << list.contains(10) << "\n";
		std::cout << list.contains(100) << "\n";
	
		std::cout << list.front() << "\n";
		std::cout << list.back() << "\n";
}
