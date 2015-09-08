#include "shapes.h"
#include <iostream>

Shape::Shape()
{
	highLeftPoint = nullPoint;
	hight = 0;
	width = 0;
	columns = 0;
	lines = 0;
	text = "\0";
	//visible = true;
}

std::ostream & operator <<(std::ostream & output, Shape* sh)
{
	output
		<< "\nType:				" << sh->type << " ; Id: " << sh->id
		<< "\nCoordinates:		x: " << sh->highLeftPoint.getX() << ", y: " << sh->highLeftPoint.getY()
		<< "\nWidth:			" << sh->width
		<< "\nHight:			" << sh->hight
		<< "\nText:				" << sh->text
		<< "\nColumns:			" << sh->columns
		<< "\nLines:			" << sh->lines << "\n";
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
	type = 'R';
	id = rectanglesCounter;
	rectanglesCounter++;
	shapesCounter++;
}

Rectangle::Rectangle(Point highLeftPoint)
{	
	type = 'R';
	id = rectanglesCounter;
	rectanglesCounter++;
	shapesCounter++;
	this->highLeftPoint = highLeftPoint;
}
Rectangle::Rectangle(Point highLeftPoint, int hight, int width)
{
	type = 'R';
	id = rectanglesCounter;
	rectanglesCounter++;
	shapesCounter++;
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
void Rectangle::show()
{
	std::cout
		<< "\nType:				" << type << " ; Id: " << id
		<< "\nCoordinates:		x: " << highLeftPoint.getX() << ", y: " << highLeftPoint.getY()
		<< "\nWidth:			" << width
		<< "\nHight:			" << hight << std::endl;
}

//Таблица

Table::Table()
{
	type = 'C';
	id = tablesCounter;
	shapesCounter++;
	tablesCounter++;
}
Table::Table(Point highLeftPoint)
{
	type = 'C';
	id = tablesCounter;
	shapesCounter++;
	tablesCounter++;
	this->highLeftPoint = highLeftPoint;
}
Table::Table(Point highLeftPoint, int hight, int width)
{
	type = 'C';
	id = tablesCounter;
	shapesCounter++;
	tablesCounter++;
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
}
Table::Table(Point highLeftPoint, int hight, int width, short int columns, short int lines)
{
	type = 'C';
	id = tablesCounter;
	shapesCounter++;
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
void Table::show()
{
	std::cout
		<< "\nType:				" << type << " ; Id: " << id
		<< "\nСoordinates:		x: " << highLeftPoint.getX() << ", y: " << highLeftPoint.getY()
		<< "\nWidth:			" << width
		<< "\nHight:			" << hight
		<< "\nColumns:			" << columns
		<< "\nLines:			" << lines << std::endl;
}

//Текст

Text::Text()
{
	type = 'T';
	id = textCounter;
	shapesCounter++;
	textCounter++;
}
Text::Text(Point highLeftPoint)
{
	type = 'T';
	id = textCounter;
	shapesCounter++;
	textCounter++;
	this->highLeftPoint = highLeftPoint;
}
Text::Text(Point highLeftPoint, std::string text)
{
	type = 'T';
	id = textCounter;
	shapesCounter++;
	textCounter++;
	this->highLeftPoint = highLeftPoint;
	this->text = text;
}
void Text::setText(std::string text)
{
	this->text = text;
}
void Text::show()
{
	std::cout
		<< "\nType:				" << type << " ; Id: " << id
		<< "\nCoordinates:		x: " << highLeftPoint.getX() << ", y: " << highLeftPoint.getY()
		<< "\nText:				" << text << std::endl;
}

//текст в прямоугольнике

TextInRectangle::TextInRectangle()
{
	type = 'I';
	id = textInRectangleCounter;
	shapesCounter++;
	textInRectangleCounter++;
}
TextInRectangle::TextInRectangle(Point highLeftPoint)
{
	type = 'I';
	id = textInRectangleCounter;
	shapesCounter++;
	textInRectangleCounter++;
	this->highLeftPoint = highLeftPoint;
}
TextInRectangle::TextInRectangle(Point highLeftPoint, std::string text)
{
	type = 'I';
	id = textInRectangleCounter;
	shapesCounter++;
	textInRectangleCounter++;
	this->text = text;
}
TextInRectangle::TextInRectangle(Point highLeftPoint, int hight, int width)
{
	type = 'I';
	id = textInRectangleCounter;
	shapesCounter++;
	textInRectangleCounter++;
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
}
TextInRectangle::TextInRectangle(Point highLeftPoint, std::string text, int hight, int width)
{
	type = 'I';
	id = textInRectangleCounter;
	shapesCounter++;
	textInRectangleCounter++;
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
	this->text = text;
}
/*void TextInRectangle::setText(std::string text)
{
	this->text = text;
}
void TextInRectangle::setHight(int hight)
{
	this->hight = hight;
}
void TextInRectangle::setWidth(int width)
{
	this->hight = hight;
}*/
void TextInRectangle::show()
{
	std::cout
		<< "\nType:				" << type << " ; Id: " << id
		<< "\nCoordinates:		x: " << highLeftPoint.getX() << ", y: " << highLeftPoint.getY()
		<< "\nWidth:			" << width
		<< "\nHight:			" << hight 
		<< "\nText:				" << text << std::endl;
}
