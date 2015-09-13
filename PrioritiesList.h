#ifndef PRIORITIESLIST_H
#define PRIORITIESLIST_H

template <typename T>
class Node
{
public:
	T data;
	Node* next;
	int priority;
	Node(T data, int priority, Node* next);
	~Node();
};

template <typename T>
class PrioritiesList
{
public:
	PrioritiesList();
	~PrioritiesList();
	bool isNull();
	int getSize();
	void add(T el, int priority);
	T* getElementByNumber(int number);
	T* getTop();
	void deleteElement(int number);
	T* pop();
	void clear();	

private:
	Node<T>* head;
	int size;
};

#endif