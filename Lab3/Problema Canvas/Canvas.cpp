#include "Canvas.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>

Canvas::Canvas(int latime, int inaltime)
{
	this->latime = latime;
	this->inaltime = inaltime;

	canvasDesen = new char* [inaltime];

	for (int i = 0; i < inaltime; i++)
	{
		canvasDesen[i] = new char [latime];
		for (int j = 0; j < latime; j++)
			canvasDesen[i][j] = ' ';
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < latime; i++)
	{
		for (int j = 0; j < inaltime; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) &&
				(i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
				SetPoint(i, j, ch);
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < latime; i++)
	{
		for (int j = 0; j < inaltime; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) < ray * ray - 15)
				//(i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
				SetPoint(i, j, ch);
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	DrawLine(left, top, right, top, ch);
	DrawLine(left, bottom, right, bottom, ch);
	DrawLine(left, top, left, bottom, ch);
	DrawLine(right, top, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left + 1; i < right; i++)
		for (int j = top + 1; j < bottom; j++)
			SetPoint(i, j, ch);
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x <= latime && y >= 0 && y <= inaltime)
		canvasDesen[y][x] = ch;
	else
		return;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = -abs(y2 - y1);
	int error = dx + dy;
	int sx = x1 < x2 ? 1 : -1;
	int sy = y1 < y2 ? 1 : -1;
	
	//printf("Before while: x1:%d, x2:%d, y1:%d, y2:%d \n", x1, x2, y1, y2);

	while (true)
	{
		//printf("Setting point: %d %d with ch: %c\n", x1, y1, ch);
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) 
			break;
		int e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x1 == x2)
				break;
			error = error + dy;
			x1 = x1 + sx;
		}

		if (e2 <= dx) 
		{
			if (y1 == y2)
				break;
			error = error + dx;
			y1 = y1 + sy;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->inaltime; i++)
	{
		for (int j = 0; j < this->latime; j++)
			printf("%c", canvasDesen[i][j]);
		printf("\n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < inaltime; i++)
		for (int j = 0; j < latime; j++)
			canvasDesen[i][j] = ' ';
}