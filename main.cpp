#include "shapes.h"
#include <iostream>

using namespace std;

void main()
{
	/*Shape* q = new TextInRectangle(Point(5,10));
	cout << q;*/
	Point p(5, 10);

	p.setXY(10.2, 15.5);

	Shape* one = new Table(p, 2, 5, 3, 4);
	cout << one;
	
	
	Shape* two = new TextInRectangle (p, "some text", 5, 15);
	cout << two;

	cout << "\n\n new text: " << two->getText() << "\n";

	cout << "second text: " << one->getText() << "\n";


	system("pause");
}