#include "shapes.h"
#include <iostream>

Shape::Shape()
{
	highLeftPoint = nullPoint;
}

std::ostream & operator <<(std::ostream & output, Shape* sh)
{
	sh->show(output);
	output
		<< "\nCoordinates:		x: " << sh->highLeftPoint.getX() << ", y: " << sh->highLeftPoint.getY();
	return output;
}

// Прямоугольник

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(Point highLeftPoint)
{	
	this->highLeftPoint = highLeftPoint;
}
Rectangle::Rectangle(Point highLeftPoint, int hight, int width)
{
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
		<< "\nThis is rectangle"
		<< "\nWidth:			" << width
		<< "\nHight:			" << hight << std::endl;
}

//Таблица

Table::Table()
{

}
Table::Table(Point highLeftPoint)
{
	this->highLeftPoint = highLeftPoint;
}
Table::Table(Point highLeftPoint, int hight, int width)
{
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
}
Table::Table(Point highLeftPoint, int hight, int width, short int columns, short int lines)
{
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
		<< "\nThis is table"
		<< "\nWidth:			" << width
		<< "\nHight:			" << hight
		<< "\nColumns:			" << columns
		<< "\nLines:			" << lines << std::endl;
}

//Текст

Text::Text()
{

}
Text::Text(Point highLeftPoint)
{
	this->highLeftPoint = highLeftPoint;
}
Text::Text(Point highLeftPoint, std::string text)
{
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
		<< "\n This is text"
		<< "\nText:				" << text << std::endl;
}

//текст в прямоугольнике

TextInRectangle::TextInRectangle()
{

}
TextInRectangle::TextInRectangle(Point highLeftPoint)
{
	this->highLeftPoint = highLeftPoint;
}
TextInRectangle::TextInRectangle(Point highLeftPoint, std::string text)
{
	this->highLeftPoint = highLeftPoint;
	this->text = text;
}
TextInRectangle::TextInRectangle(Point highLeftPoint, int hight, int width)
{
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
}
TextInRectangle::TextInRectangle(Point highLeftPoint, std::string text, int hight, int width)
{
	this->highLeftPoint = highLeftPoint;
	this->hight = hight;
	this->width = width;
	this->text = text;
}

void TextInRectangle::show(std::ostream & output)
{
	output
		<< "\nThis is text in rectangle"
		<< "\nWidth:			" << width
		<< "\nHight:			" << hight 
		<< "\nText:				" << text << std::endl;
}
