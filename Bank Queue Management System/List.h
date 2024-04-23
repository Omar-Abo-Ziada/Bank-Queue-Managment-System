#pragma once

#include <iostream>
using namespace std;

#include"Node.h"

template<typename T>
class List
{
public:

	Node<T>* head;
	Node<T>* tail;

	int size;

	List()
	{
		head = nullptr;
		tail = nullptr;

		size = 0;
	}

	void Add(T data)
	{
		size++;

		Node<T>* newNode = new Node<T>(data);

		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	void Display()
	{
		Node<T>* current = head;

		while (current != nullptr)
		{
			cout << current->data.ToString();
			current = current->next;
		}
		cout << " ------------------- \n";
	}

	void Remove(T data)
	{
		size--;

		Node<T>* node = GetNodeByData(data);

		if (node == nullptr)
			return;

		if (node == head)
		{
			if (node == tail)
			{
				head = tail = nullptr;
			}
			else
			{
				head = head->next;
				head->prev = nullptr;
			}
		}
		else if (node == tail)
		{
			tail = tail->prev;
			tail->next = nullptr;
		}
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		delete node;
	}

	Node<T>* GetNodeByData(T data)
	{
		Node<T>* current = head;

		while (current != nullptr)
		{
			if (data == current->data)
				return current;

			current = current->next;
		}
		return nullptr;
	}

	bool IsEmpty()
	{
		return head == nullptr ;
	}
};

