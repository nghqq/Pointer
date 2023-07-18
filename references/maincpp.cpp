#include<iostream>



void main() 
{
	setlocale(LC_ALL, "");

	int a = 2;
	int& ra = a;
	ra += 3;
	std::cout << a << std::endl;
	std::cout << &ra << std::endl;

}