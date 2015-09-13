#include "shapes.h"
#include <iostream>

Shape::Shape()
{
	highLeftPoint = nullPoint;
	/*hight = 0;
	width = 0;
	columns = 0;
	lines = 0;
	text = "\0";*/
}

std::ostream & operator <<(std::ostream & output, Shape* sh)
{
	output
		<< "\nType:				" << sh->type << " ; Id: " << sh->id
		<< "\nCoordinates:		x: " << sh->highLeftPoint.getX() << ", y: " << sh->highLeftPoint.getY();
	sh->show(output);
	return output;
}

static int shapesCounter = 0;
static int rectanglesCounter = 0;
static int tablesCounter = 0;
static int textCounter = 0;
static int textInRectangleCounter = 0;

// Прямоугольник

Rectangle::Rectangle()
{
	type = "Rectangle";
	id = rectanglesCounter;
	rectanglesCounter++;
}

Rectangle::Rectangle(Point highLeftPoint)
{	
	type = "Rectangle";
	id = rectanglesCounter;
	rectanglesCounter++;
	this->highLeftPoint = highLeftPoint;
}
Rectangle::Rectangle(Point highLeftPoint, int hight, int width)
{
	type = "Rectangle";
	id = rectanglesCounter;
	rectanglesCounter++;
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
}
void Rectangle::setHight(int hight)
{
	this->hight = hight;
}
void Rectangle::setWidth(int width)
{
	this->width = width;
}
void Rectangle::show(std::ostream & output)
{
	output
		<< "\nWidth:			" << width
		<< "\nHight:			" << hight << std::endl;
}

//Таблица

Table::Table()
{
	type = "Table";
	id = tablesCounter;
	tablesCounter++;
}
Table::Table(Point highLeftPoint)
{
	type = "Table";
	id = tablesCounter;
	tablesCounter++;
	this->highLeftPoint = highLeftPoint;
}
Table::Table(Point highLeftPoint, int hight, int width)
{
	type = "Table";
	id = tablesCounter;
	tablesCounter++;
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
}
Table::Table(Point highLeftPoint, int hight, int width, short int columns, short int lines)
{
	type = "Table";
	id = tablesCounter;
	tablesCounter++;
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
	this->columns = columns;
	this->lines = lines;
}
void Table::setHight(int hight)
{
	this->hight = hight;
}
void Table::setWidth(int width)
{
	this->width = width;
}
void Table::setColumns(short int columns)
{
	this->columns = columns;
}
void Table::setLines(short int lines)
{
	this->lines = lines;
}
void Table::show(std::ostream & output)
{
	output
		<< "\nWidth:			" << width
		<< "\nHight:			" << hight
		<< "\nColumns:			" << columns
		<< "\nLines:			" << lines << std::endl;
}

//Текст

Text::Text()
{
	type = "Text";
	id = textCounter;
	textCounter++;
}
Text::Text(Point highLeftPoint)
{
	type = "Text";
	id = textCounter;
	textCounter++;
	this->highLeftPoint = highLeftPoint;
}
Text::Text(Point highLeftPoint, std::string text)
{
	type = "Text";
	id = textCounter;
	textCounter++;
	this->highLeftPoint = highLeftPoint;
	this->text = text;
}
void Text::setText(std::string text)
{
	this->text = text;
}
void Text::show(std::ostream & output)
{
	output
		<< "\nText:				" << text << std::endl;
}

//текст в прямоугольнике

TextInRectangle::TextInRectangle()
{
	type = "TextInRectangle";
	id = textInRectangleCounter;
	textInRectangleCounter++;
}
TextInRectangle::TextInRectangle(Point highLeftPoint)
{
	type = "TextInRectangle";
	id = textInRectangleCounter;
	textInRectangleCounter++;
	this->highLeftPoint = highLeftPoint;
}
TextInRectangle::TextInRectangle(Point highLeftPoint, std::string text)
{
	type = "TextInRectangle";
	id = textInRectangleCounter;
	textInRectangleCounter++;
	this->text = text;
}
TextInRectangle::TextInRectangle(Point highLeftPoint, int hight, int width)
{
	type = "TextInRectangle";
	id = textInRectangleCounter;
	textInRectangleCounter++;
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
}
TextInRectangle::TextInRectangle(Point highLeftPoint, std::string text, int hight, int width)
{
	type = "TextInRectangle";
	id = textInRectangleCounter;
	textInRectangleCounter++;
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
	this->text = text;
}

void TextInRectangle::show(std::ostream & output)
{
	output
		<< "\nWidth:			" << width
		<< "\nHight:			" << hight 
		<< "\nText:				" << text << std::endl;
}
