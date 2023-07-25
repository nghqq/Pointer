#include<iostream>
//#include <crtdbg.h>
//#define _CRTDBG_MAP_ALLOC
#define tab "\t"
#define delimeter "\n--------------------------------------------------\n"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_back(int* arr, int& n, int value);
void Push_front(int*& arr, int n, int value);
void Pop_back(int*& arr, int& n);


void main()
{
	setlocale(LC_ALL, "");
	int n; //Кол-во эллементов массива
	std::cout << "Введите размер массива: "; std::cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	std::cout << "Введите число: "; std::cin >> value;
	arr = Push_back(arr, n, value);
	Print(arr, n);
	Pop_back(arr, n);
	Print(arr, n);
	delete[] arr;
	//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	//_CrtDumpMemoryLeaks();

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << std::endl;
}

int* Push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;


}
void Push_front(int*& arr, int& n, int value)
{

}
void Pop_back(int*& arr, int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n--;
}



