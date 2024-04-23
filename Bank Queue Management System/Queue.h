#pragma once

#include"Node.h"
#include"DequeueResult.h"

template <typename T>
class Queue
{
public:

	Node<T>* front;
	Node<T>* rear;
	Node<T>* current;
	int size;

	Queue()
	{
		front = nullptr;
		rear = nullptr;
		current = nullptr;
	}

	void Enqueue(T data)
	{
		size += 1;

		Node<T>* newNode = new Node<T>(data);

		if (front == nullptr)
		{
			current = newNode;
			current->prev = rear;
		}
		else
		{
			current->next = newNode;
			current = newNode;
		}

		rear = current;

		if (front == nullptr)
		{
			front = rear;
		}
	}

	DequeueResult<T> Dequeue()
	{
		DequeueResult<T> Result;

		if (front != nullptr)
		{
			size -= 1;
			Result.IsSuccess = true;
			Result.Value = front->data;

			Node<T>* temp = front;
			front = front->next;
			delete temp;
		}
		else
		{
			Result.IsSuccess = false;
		}
		return Result;
	}

	bool IsEmpty()
	{
		return front == nullptr ;
	}

	bool IsFirstNode() 
	{
		return ( front == rear && front != nullptr ) ;
	}
};

