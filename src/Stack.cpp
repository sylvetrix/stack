#include "src/Stack.hpp"
#include <cstdlib>

using namespace std;

template <class T>
Stack<T>::Stack()
{
	this->head = NULL;
	this->tail = NULL;
}

template <class T>
Stack<T>::~Stack()
{
	while (this->head != NULL)
	{
		StackNode<T>* tempNode = this->head;

		if (this->head == this->tail)
		{
			this->head = NULL;
			this->tail = NULL;
		}
		else
		{
			this->head = this->head->next;
		}

		delete tempNode;
	}
}

template <class T>
T Stack<T>::pop()
{
	if (this->head != NULL)
	{
		T temp = this->head->value;
		this->head->value = NULL;
		StackNode<T>* tempNode = this->head;

		if (this->head == this->tail)
		{
			this->head = NULL;
			this->tail = NULL;
		}
		else
		{
			this->head = this->head->next;
		}

		delete tempNode;
		return temp;
	}

	return T();
}

template <class T>
void Stack<T>::push(T element)
{
	StackNode<T>* tempNode = new StackNode<T>();
	tempNode->value = element;

	if (this->head == NULL)
	{
		this->head = tempNode;
		this->tail = tempNode;
	}
	else
	{
		tempNode->next = this->head;
		this->head = tempNode;
	}
}

