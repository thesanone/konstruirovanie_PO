#ifndef PRIORITIESLIST_H
#define PRIORITIESLIST_H

#include <iostream>
#include <locale>

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


class ExceptionLinkToNULL
{
public:
	static int timeToStart;
	std::string message;
	int steps_left;
	std::string nameFunction;
	int timecur;
	ExceptionLinkToNULL(std::string m) :message(m) {}
	ExceptionLinkToNULL(int k, std::string m) :steps_left(k),message(m){}
	ExceptionLinkToNULL(std::string name, int curTime, std::string m) : nameFunction(name), timecur(curTime), message(m){}
	ExceptionLinkToNULL(std::string name, int curTime, int k, std::string m) : nameFunction(name), timecur(curTime), steps_left(k), message(m){}

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
		if (number > size) return;
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
				else
				{
					int dt = clock();
					throw ExceptionLinkToNULL("Iterator++ ", dt - ExceptionLinkToNULL::timeToStart , "Cant go to next, current element is null\n");
				}
			}
			catch (ExceptionLinkToNULL e)
			{
				cout << "\nExeption: in function " << e.nameFunction;
				cout << ", in " << e.timecur;
				cout << "ms per start, steps left " << e.steps_left;
				cout << ", what happens ? " << e.message;
			}
			return *this;
		}
		Iterator& operator+=(int k)
		{
			try
			{
				for (int i = 0; i < k; i++)
					if (current != NULL) current = current->next;
					else
					{
						int dt = clock();
						throw ExceptionLinkToNULL("Iterator+=", dt - ExceptionLinkToNULL::timeToStart , k - i, "Cant go to next, current element is null\n	Steps left: ");
					}
			}
			catch (ExceptionLinkToNULL e)
			{
				cout << "\nExeption: in function " << e.nameFunction;
				cout << ", in " << e.timecur;
				cout << "ms per start, steps left " << e.steps_left;
				cout << ", what happens ? " << e.message;
			}
			return *this;
		}
		bool operator==(const Iterator& other){ return current == other.current; }
		bool operator!=(const Iterator& other){ return !(*this == other.current); }
		Node<T>& operator*(){
			try
			{
				if (current == NULL){
					int dt = clock();
					throw ExceptionLinkToNULL("", dt - ExceptionLinkToNULL::timeToStart , "Requested access to the NULL point\n");
				}
				else return *current;
			}
			catch (ExceptionLinkToNULL e)
			{
				cout << "\nExeption: in function " << e.nameFunction;
				cout << ", in " << e.timecur;
				cout << "ms per start, steps left " << e.steps_left;
				cout << ", what happens ? " << e.message;
			}
		}
		Node<T>* operator->(){
			try
			{
				if (current == NULL){
					int dt = clock();
					throw ExceptionLinkToNULL("", dt - ExceptionLinkToNULL::timeToStart , "Requested access to the NULL point\n");
				}
			}
			catch (ExceptionLinkToNULL e)
			{
				cout << "\nExeption: in function " << e.nameFunction;
				cout << ", in " << e.timecur;
				cout << "ms per start, steps left " << e.steps_left;
				cout << ", what happens ? " << e.message;
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