#pragma once

#include <windows.h>
#include<iostream>
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
#include <cctype>
#include <vector>

using namespace std;
template<class T>
class DoubleLinkedList {
	class Node {
	public:
		T data;
		Node* prev;
		Node* next;
		Node() {};
		Node(const T& data) {
			this->data = data;
			this->prev = nullptr;
			this->next = nullptr;
		}
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
public:
	DoubleLinkedList() {};
	void AddBegin(const T& data) {
		Node* node = new Node(data);
		if (head == nullptr) {
			head = tail = node;
		}
		else {
			head->prev = node;
			node->next = head;
			head = node;

		}

		size++;

	}
	// Add these methods to enable range-based for loops
	T* begin() {
		return head ? &head->data : nullptr;
	}

	T* end() {
		return nullptr; // Indicates the end of the list
	}

	const T* begin() const {
		return head ? &head->data : nullptr;
	}

	const T* end() const {
		return nullptr; // Indicates the end of the list
	}
	DoubleLinkedList(const DoubleLinkedList& other) {
		Node* current = other.head; 
		while (current != nullptr) {
			AddEnd(current->data); 
			current = current->next;
		}
	}
	DoubleLinkedList& operator=(const DoubleLinkedList& other) {
		if (this == &other) {
			return *this; 
		}

		while (head != nullptr) {
			DeleteBegin();
		}

		Node* current = other.head;
		while (current != nullptr) {
			AddEnd(current->data);
			current = current->next;
		}

		return *this;
	}

	void AddEnd(const T& data) {
		Node* node = new Node(data);
		if (tail == nullptr) {
			head = tail = node;
		}
		else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		size++;
	}

	void DeleteBegin() {
		if (head == nullptr) {
			assert(!"List is empty");
		}
		else {
			Node* temp = head;
			if (head == tail) {
				head = tail = nullptr;
			}
			else {
				head = head->next;
				head->prev = nullptr;
			}
			delete temp;
			size--;
		}
	}

	void DeleteEnd() {
		if (tail == nullptr) {
			assert(!"List is empty");
		}
		else {
			Node* temp = tail;
			if (head == tail) {
				head = tail = nullptr;
			}
			else {
				tail = tail->prev;
				tail->next = nullptr;
			}
			delete temp;
			size--;
		}
	}

	void DeleteIndex(int index) {
		if (index<0 || index>size - 1) {
			assert(!"Index is wrong...");
		}
		else if (index == 0) {
			DeleteBegin();
		}
		else if (index == size - 1) {
			DeleteEnd();
		}
		else {
			Node* current_node = head;
			for (size_t i = 0; i < index; i++)
			{
				current_node = current_node->next;
			}
			current_node->prev->next = current_node->next;
			current_node->next->prev = current_node->prev;
			delete current_node;
			size--;
		}
		
		
	}


	T& operator[](int index) {
		if (index < 0 || index >= size) {
			assert(!"Index out of bounds");
		}
		Node* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		return current->data;
	}

	int Size() const {
		return size;
	}

	void Print() const {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	~DoubleLinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}
};

