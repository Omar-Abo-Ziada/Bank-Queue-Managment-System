#pragma once

template<typename T>
struct Node
{
	Node* next;
	Node* prev;
	T data;

	Node( T _data) 
	{
		data = _data;
		next = nullptr; 
		prev = nullptr; 
	}
	Node()
	{
		next = nullptr;
		prev = nullptr;
	}
};
