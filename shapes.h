#ifndef SHAPES_H
#define SHAPES_H

#include <string>

class Point
{
private:
	float x, y;
public:
	Point(){}
	Point(float x, float y) : x(x), y(y){}
	float getX() { return x; }
	float getY() { return y; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void setXY(float x, float y) { this->x = x; this->y = y; }
};

const Point nullPoint = Point(0.0, 0.0);

class Shape
{
	friend std::ostream & operator <<(std::ostream & output, Shape* sh);
protected:
	int id;
	char type;
	Point highLeftPoint;
	int hight, width;
	short int columns, lines;
	std::string text;
	//bool visible;
public:
	Shape();
	~Shape(){}
	void moveTo(Point p) { highLeftPoint = p; }
	/*void setVisible(bool visible) { this->visible = visible; }
	bool getVisible() { return visible; }*/
	int getID() { return id; }
	char getType() { return type; }

	virtual void setHight(int hight){}
	virtual void setWidth(int width){}
	virtual void setColumns(short int columns){}
	virtual void setLines(short int lines){}
	virtual void setText(std::string text){}

	virtual void show() = 0;
};

std::ostream & operator <<(std::ostream & output, Shape* sh);

class Rectangle :public virtual Shape
{
public:
	Rectangle();
	Rectangle(Point highLeftPoint);
	Rectangle(Point highLeftPoint, int hight, int width);
	void setHight(int hight);
	void setWidth(int width);
	void show();
};

class Table :public Shape
{
public:
	Table();
	Table(Point highLeftPoint);
	Table(Point highLeftPoint, int hight, int width);
	Table(Point highLeftPoint, int hight, int width, short int columns, short int lines);
	void setHight(int hight);
	void setWidth(int width);
	void setColumns(short int columns);
	void setLines(short int lines);
	void show();
};

class Text :public virtual Shape
{
public:
	Text();
	Text(Point highLeftPoint);
	Text(Point highLeftPoint, std::string text);
	void setText(std::string text);
	void show();
};
	
class TextInRectangle :public Text, public Rectangle
{
public:
	TextInRectangle();
	TextInRectangle(Point highLeftPoint);
	TextInRectangle(Point highLeftPoint, std::string text);
	TextInRectangle(Point highLeftPoint, int hight, int width);
	TextInRectangle(Point highLeftPoint, std::string text, int hight, int width);
	void show();
};

#endif