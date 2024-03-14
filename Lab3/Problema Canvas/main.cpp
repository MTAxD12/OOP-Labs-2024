#define _CRT_SECURE_NO_WARNINGS
#include "Canvas.h"
#include<iostream>

Canvas canvas(70, 35);

int main() 
{
	canvas.SetPoint(10, 10, 'P');
	canvas.DrawRect(0, 10, 20, 20, 'A');
	canvas.FillRect(0, 10, 20, 20, 'a');
	canvas.DrawLine(10, 5, 30, 30, '*');
	canvas.Print();
	canvas.Clear();
	canvas.DrawRect(0, 10, 20, 20, 'a');
	canvas.DrawLine(10, 5, 30, 30, '*');
	canvas.Print();
	canvas.Clear();
	canvas.DrawCircle(15, 15, 15, 'c');
	canvas.DrawCircle(47, 15, 15, 'd');	
	canvas.FillCircle(47, 15, 15, 'x');
	//canvas.FillCircle(45, 15, 15, 'x');
	canvas.Print();

	return 0;
}