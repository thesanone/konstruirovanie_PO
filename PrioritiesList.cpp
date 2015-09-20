#include "PrioritiesList.h"
int ExceptionLinkToNULL::timeToStart = 0;

/*

template <typename T>
Node<T>::Node(T data, int priority, Node<T>* next)
{
	this->data = data;
	this->priority = priority;
	this->next = next;
}

template <typename T>
Node<T>::~Node()
{
	cout << "\nelement priority: " << priority << "is deleted";
	delete next;
}

template <typename T>
PrioritiesList<T>::PrioritiesList()
{
	head = NULL;
	size = 0;
}

template <typename T>
PrioritiesList<T>::~PrioritiesList()
{
	this->clear();
}

template <typename T>
void PrioritiesList<T>::clear()
{
	delete head;
}

template <typename T>
bool PrioritiesList<T>::isNull()
{
	return (head == NULL);
}

template <typename T>
int PrioritiesList<T>::getSize()
{
	return size;
}

template <typename T>
void PrioritiesList<T>::add(T el, int priority)
{
	if (head->priority < priority)
	{
		Node<T>* newEl = new Node<T>(el, priority, head);
		head = newEl;
	}
	else
	{
		Node<T>* temp = head;
		while (temp->next != NULL && priority >= temp->next->priority) temp = temp->next;
		
		Node<T>* newEl = new Node<T>(el, priority, temp->next);
		temp->next = newEl;
	}
}

template <typename T>
T* PrioritiesList<T>::getElementByNumber(int number)
{
	if (number > size) return NULL;
	Node<T>* temp = head;
	for (int i = 1; i < number; i++)
		temp = temp->next;
	return temp->data;
}

template <typename T>
T* PrioritiesList<T>::getTop()
{
	return head->data;
}

template <typename T>
void PrioritiesList<T>::deleteElement(int number)
{
	if (number > size) return NULL;
	Node<T>* temp = head;
	for (int i = 1; i < number-1; i++)
		temp = temp->next;
	Node<T>* _next = temp->next;
	temp = _next->next;
	delete _next;
}

template <typename T>
T* PrioritiesList<T>::pop()
{
	T retValue = head->data;
	Node<T>* temp = head->next;
	head->next = NULL;
	head = temp;
}*/
