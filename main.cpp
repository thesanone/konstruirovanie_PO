#include "shapes.h"
#include <iostream>

using namespace std;

void main()
{
	/*Shape* q = new TextInRectangle(Point(5,10));
	cout << q;*/
	Point p(5, 10);
	Rectangle r(p, 2, 3);
	r.show();
	p.setXY(10.2, 15.5);
	Table table(p, 10, 20, 1, 1);
	table.show();
	p.setXY(100.1, 12312.12321);
	table.moveTo(p);
	table.show();

	Shape* one = new Table(p, 2, 5, 3, 4);
	cout << one;

	
	Shape* two = new TextInRectangle (p, "some text", 5, 15);
	cout << two;

	system("pause");
}