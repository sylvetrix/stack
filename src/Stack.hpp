#ifndef STACK_H
#define STACK_H

#include <cstdlib>

template <class T>
struct StackNode
{
	T value;
	StackNode<T>* next;
};

template <class T>
class Stack
{
	public:
		Stack();
		~Stack();
		bool isEmpty() { return head == NULL; }
		T pop();
		void push(T);

	private:
		StackNode<T>* head;
		StackNode<T>* tail;
};

#endif

