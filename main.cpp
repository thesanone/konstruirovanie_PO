#include "shapes.h"
#include "PrioritiesList.h"
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <ctime>

using namespace std;

void main()
{
	Point p(5, 10);
	p.setXY(10, 15);

	Shape* mas[4];
	Shape* one = new Table(p, 2, 5, 3, 4);
	mas[0] = one;
//	cout << one;
	
	Shape* two = new TextInRectangle (p, "some text", 5, 15);
	mas[1] = two;

	Shape* three = new Rectangle(p, 7,3);
	mas[2] = three;

	p.setXY(-3, -8.5);

	Shape* four = new Text(p, "Hi, i'm fourth figure");
	mas[3] = four;

	for (int i = 0; i < 4; i++)
	{
		cout << mas[i];
	}
	cout << "\n\n Move to point (6, 20)\n\n";
	for (int i = 0; i < 4; i++)
	{
		mas[i]->moveTo(Point(6, 20));
		cout << mas[i];
	}


	/*******************************************************************/
	/*Стандартные контейнеры stl*/
	/*******************************************************************/
	// контейнер vector 
	cout << "\n\nVector: " << endl;
	vector<string> v;
	for (int i = 0; i<5; i++)
	{
		v.push_back(string(i + 1, 'a'));
	}
	for (int i = 0; i<v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << endl;


	// контейнер list
	cout << "List: " << endl;
	list<string> l;
	for (int i = 0; i<5; i++)
	{
		l.push_back(string(i + 1, 'a'));
	}
	list<string>::iterator lp;
	while (!l.empty())
	{
		lp = l.begin();
		cout << *lp << endl;
		l.pop_front();
	}
	cout << endl;


	// контейнер deque 
	cout << "Deque: " << endl;
	deque<string> de;
	for (int i = 0; i<5; i++)
	{
		if (i % 2 == 0)
		{
			de.push_back(string(i + 1, 'a'));
		}
		else
		{
			de.push_front(string(i + 1, 'a'));
		}
	}
	for (int i = 0; i<de.size(); i++)
	{
		cout << de[i] << endl;
	}
	cout << endl;

	// контейнер stack 
	cout << "Stack: " << endl;
	stack<string, vector<string> > st;
	for (int i = 0; i<5; i++)
	{
		st.push(string(i + 1, 'a'));
	}

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	cout << endl;


	// контейнер queue
	cout << "Queue: " << endl;
	queue<string, list<string> > qu;
	for (int i = 0; i<5; i++)
	{
		qu.push(string(i + 1, 'a'));
	}
	while (!qu.empty())
	{
		cout << qu.front() << endl;
		qu.pop();
	}
	cout << endl;

	//контейнер map
	cout << "Map: " << endl;
	map<int, string> m;
	for (int i = 0; i<10; i++)
	{
		m.insert(pair<int, string>(i, string(i + 1, 'a')));

	}
	map<int, string>::iterator mit;
	for (int i = 0; i<m.size(); i++)
	{
		mit = m.find(i);
		cout << mit->second << endl;
	}
	cout << endl;

	/*******************************************************************/
	/*Очередь с приоритетом на базхе списка*/
	/*******************************************************************/

	PrioritiesList<int> plist;

	plist.add(111, 20);
	plist.add(333, 10);
	plist.add(444, 0);
	plist.add(222, 15);

	for (PrioritiesList<int>::Iterator i = plist.begin(); !i.empty(); i++)
	{
		cout
			<< "\nData:		" << i->data
			<< "\nPriority	" << i->priority << endl;
	}

	plist.clear();

	PrioritiesList<Shape*> slist;
	slist.add(one, 20);
	slist.add(two, 10);
	slist.add(three, 0);
	slist.add(four, 15);

	for (PrioritiesList<Shape*>::Iterator i = slist.begin(); !i.empty(); i++)
	{
		cout
			<< "\nData:		" << i->data
			<< "\nPriority	" << i->priority << endl;
	}

	slist.clear();
	try
	{
		PrioritiesList<Shape*>::Iterator it = slist.begin();
		it++;

		it += 5;
	}
	catch (ExceptionLinkToNULL e)
	{
		cout << "\nExeption: in function " << e.nameFunction;
		cout << ", in " << e.timecur;
		cout << "ms per start, steps left " << e.steps_left;
		cout << ", what happens ? " << e.message;
	}
	system("pause");
}