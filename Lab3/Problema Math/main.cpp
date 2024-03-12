#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include<iostream>

Math fct;

int main() 
{
	int a = 23, b = 34, c = 124;
	double ad = 0.5, bd = 10.0, cd = 3.0;
	char s1[] = "string1", s2[] = "string2";
	printf("a = 23, b = 34, c = 124\n");
	printf("ad = 0.5, bd = 10.0, cd = 3.0\n");
	printf("str1 = 'string1', str2 = 'string2'\n\n");
	printf("a + b =        %d\n", fct.Add(a, b));
	printf("a + b + c =    %d\n", fct.Add(a, b, c));
	printf("ad + bd =      %d\n", fct.Add(ad, bd));
	printf("ad + bd + cd = %d\n", fct.Add(ad, bd, cd));
	printf("a * b =        %d\n", fct.Mul(a, b));
	printf("a * b * c =    %d\n", fct.Mul(a, b, c));
	printf("ad * bd =      %d\n", fct.Mul(ad, bd));
	printf("ad * bd * cd = %d\n", fct.Mul(ad, bd, cd));
	printf("a + b + c + 23 + 35 + 212 = %d\n", fct.Add(6, a, b, c, 23, 35, 212));
	printf("str1 + str2 = %s\n", fct.Add(s1, s2));
}