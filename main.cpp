#include "shapes.h"
#include "PrioritiesList.h"
#include <iostream>
#include <list>

using namespace std;

void main()
{
	/*Shape* q = new TextInRectangle(Point(5,10));
	cout << q;*/

	Point p(5, 10);
	p.setXY(10, 15);

	Shape* one = new Table(p, 2, 5, 3, 4);
	cout << one;
	
	Shape* two = new TextInRectangle (p, "some text", 5, 15);
	cout << two;
	cout << "\n\n new text: " << two->getText() << "\n";
	cout << "second text: " << one->getText() << "\n";

	Shape* three = new Rectangle(p, 7,3);
	cout << three << endl << "Rectangle " + three->getID() << " move to point 6, 20";
	three->moveTo(Point(6, 20));
	cout <<endl<<  three;

	p.setXY(-3, -8.5);

	Shape* four = new Text(p, "Hi, i'm fourth figure");
	cout << four
		<< endl << "Text " + four->getID() << " move to point 17, 24";
	four->moveTo(Point(17, 24));
	cout << endl << four;
	
	PrioritiesList<int> list;

	
	list.add(111, 20);
	list.add(333, 10);
	list.add(444, 0);
	list.add(222, 15);

	for (PrioritiesList<int>::Iterator i = list.begin(); i.empty(); i++)
	{
		cout
			<< "\nData:		" << i->data
			<< "\nPriority	" << i->priority << endl;
	}

	list.clear();

	system("pause");
}