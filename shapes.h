#ifndef SHAPES_H
#define SHAPES_H

#include <string>

class Point
{
private:
	int x, y;
public:
	Point(){}
	Point(int x, int y) : x(x), y(y){}
	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setXY(int x, int y) { this->x = x; this->y = y; }
};

const Point nullPoint = Point(0.0, 0.0);

class Shape
{
	friend std::ostream & operator <<(std::ostream & output, Shape* sh);
protected:
	Point highLeftPoint;
public:
	Shape();
	~Shape(){}
	void moveTo(Point p) { highLeftPoint = p; }
	Point getHighLeftPoint() { return highLeftPoint; }

	virtual void show(std::ostream & output) = 0;
};

std::ostream & operator <<(std::ostream & output, Shape* sh);

class Rectangle :public virtual Shape
{
protected:
	int hight, width;
public:
	Rectangle();
	Rectangle(Point highLeftPoint);
	Rectangle(Point highLeftPoint, int hight, int width);
	void setHight(int hight);
	int getHight(){ return hight; }
	void setWidth(int width);
	int getWidth(){ return width; }
	void show(std::ostream & output);
};

class Table :public Shape
{
private:
	short int columns, lines;
	int hight, width;
public:
	Table();
	Table(Point highLeftPoint);
	Table(Point highLeftPoint, int hight, int width);
	Table(Point highLeftPoint, int hight, int width, short int columns, short int lines);
	void setHight(int hight);
	int getHight(){ return hight; }
	void setWidth(int width);
	int getWidth(){ return width; }
	void setColumns(short int columns);
	short int getColumns(){ return columns; }
	void setLines(short int lines);
	short int getLines(){ return lines; }
	void show(std::ostream & output);
};

class Text :public virtual Shape
{
protected:
	std::string text;
public:
	Text();
	Text(Point highLeftPoint);
	Text(Point highLeftPoint, std::string text);
	void setText(std::string text);
	std::string getText(){ return text; }
	void show(std::ostream & output);
};
	
class TextInRectangle :public Text, public Rectangle
{
public:
	TextInRectangle();
	TextInRectangle(Point highLeftPoint);
	TextInRectangle(Point highLeftPoint, std::string text);
	TextInRectangle(Point highLeftPoint, int hight, int width);
	TextInRectangle(Point highLeftPoint, std::string text, int hight, int width);
	void show(std::ostream & output);
};

#endif