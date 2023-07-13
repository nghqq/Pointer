#include <iostream>
//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS


	int a = 2;
	int* pa = &a;
	// pa - pointer to 'a'
	std::cout << a << std::endl; // вывод значения переменной a на экран
	std::cout << &a << std::endl; // взятие адреса переменной a прямо при выводе

	std::cout << pa << std::endl; // вывод адреса переменной a хранящегося в указатели pa
	std::cout << *pa << std::endl; // разыменновывыем укзатель pa и получаем значение переменной a

	int* pb;
	int b = 3;
	pb = &b;

	std::cout << *pb << std::endl;

	//int - int
	//int* - указатель на int
	// double - double
	// double* - указатель на double 

#endif // POINTERS_BASICS


	const int n = 5;
	short arr[n] = { 3,5,8,13,21 };

	std::cout << arr << std::endl;
	std::cout << std::endl;
	std::cout << *arr << std::endl;
	
	

	for (int  i = 0; i < n; i++)
	{
		std::cout << *(arr+i) << "\t";
		
	}
	std::cout << std::endl;
}