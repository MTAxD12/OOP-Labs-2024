#include "Canvas.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>

Canvas::Canvas(int lines, int columns)
{
	this->columns = columns;
	this->lines = lines;

	canvasDesen = new char* [lines];

	for (int i = 0; i < lines; i++)
	{
		canvasDesen[i] = new char [columns];
		for (int j = 0; j < columns; j++)
			canvasDesen[i][j] = ' ';
	}
	//printf("lines: %d, columns: %d", lines, columns);
}

void Canvas::set_pixel(int x, int y, char ch)
{
	if ((x >= 0 && x <= columns) && (y >= 0 && y <= lines))
		canvasDesen[y][x] = ch;
	else
		return;
}

void Canvas::set_pixels(int count, ...)
{
	va_list param;
	va_start(param, count * 2 + count);

	for (int i = 0; i < count * 2 + count; i += 3)
	{
		int x = va_arg(param, int);
		int y = va_arg(param, int);
		char c = va_arg(param, char);
		set_pixel(y, x, c);
	}
}


void Canvas::print() const
{
	for (int i = 0; i < this->lines; i++)
	{
		for (int j = 0; j < this->columns; j++)
			printf("%c", canvasDesen[i][j]);
		printf("\n");
	}
}

void Canvas::clear()
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			canvasDesen[i][j] = ' ';
}
