#ifndef PRIORITIESLIST_H
#define PRIORITIESLIST_H

#include <iostream>

template <typename T>
class Node
{
public:
	T data;
	Node* next;
	int priority;
	Node(T data, int priority, Node<T>* next)
	{
		this->data = data;
		this->priority = priority;
		this->next = next;
	}
};


class ExeptionLinkToNULL
{
public:
	std::string message;
	int steps_left;
	ExeptionLinkToNULL(std::string m) :message(m) {}
	ExeptionLinkToNULL(std::string m, int k) :message(m), steps_left(k) {}
};



template <typename T>
class PrioritiesList
{
public:
	PrioritiesList()
	{
		head = NULL;
		size = 0;
	}

	~PrioritiesList() { this->clear(); }

	bool isNull() { return (head == NULL); }

	int getSize() const { return size; }

	void add(T el, int priority)
	{
		if (head == NULL)
		{
			Node<T>* newEl = new Node<T>(el, priority, head);
			head = newEl;
		}
		else
		{
			if (head->priority < priority)
			{
				Node<T>* newEl = new Node<T>(el, priority, head);
				head = newEl;
			}
			else
			{
				Node<T>* temp = head;
				while (temp->next != NULL && priority <= temp->next->priority) temp = temp->next;

				Node<T>* newEl = new Node<T>(el, priority, temp->next);
				temp->next = newEl;
			}
		}
		size++;
	}

	T* getElementByNumber(int number)
	{
		if (number > size) return NULL;
		Node<T>* temp = head;
		for (int i = 1; i < number; i++)
			temp = temp->next;
		return temp->data;
	}

	void deleteElement(int number)
	{
		if (number > size) return NULL;
		Node<T>* temp = head;
		for (int i = 1; i < number - 1; i++)
			temp = temp->next;
		Node<T>* _next = temp;
		temp = _next->next;
		delete _next;
	}

	T* pop()
	{
		if (head == NULL) return NULL;
		T retValue = head->data;
		Node<T>* temp = head->next;
		head->next = NULL;
		head = temp;
	}

	void clear()
	{
		while (head != NULL)
		{
			Node<T>* _next = head;
			head = head->next;
			delete _next;
		}
	}

	class Iterator
	{
	public:
		Iterator(Node<T>* current) :current(current){}
		Iterator& operator++() {
			try
			{
				if (current != NULL) current = current->next;
				else throw ExeptionLinkToNULL("Exception: Cant go to next, current element is null\n");
			}
			catch (ExeptionLinkToNULL e)
			{
				cout << e.message;
			}
			return *this;
		}
		Iterator& operator+=(int k)
		{
			try
			{
				for (int i = 0; i < k; i++)
					if (current != NULL) current = current->next;
					else throw ExeptionLinkToNULL("Exception: Cant go to next, current element is null\n	Steps left: ", k-i);
			}
			catch (ExeptionLinkToNULL e)
			{
				cout << e.message << e.steps_left << endl;
			}
			return *this;
		}
		bool operator==(const Iterator& other){ return current == other.current; }
		bool operator!=(const Iterator& other){ return !(*this == other.current); }
		Node<T>& operator*(){
			try
			{
				if (current == NULL) throw ExeptionLinkToNULL("Exception: requested access to the NULL point\n")
				else return *current;
			}
			catch (ExeptionLinkToNULL e)
			{
				cout << e.message;
			}
		}
		Node<T>* operator->(){
			try
			{
				if (current == NULL) throw ExeptionLinkToNULL("Exception: requested access to the NULL point\n");
			}
			catch (ExeptionLinkToNULL e)
			{
				cout << e.message;
			}
			return current; }
		bool empty(){ return current == NULL; }
		Iterator& operator=(const Iterator& other)
		{
			if (this != &other)
			{
				current = other.current;
			}
			return *this;
		}
	private:
		Node<T>* current;
	};
	Iterator begin() { return Iterator(head); }

private:
	Node<T>* head;
	int size;
};

#endif