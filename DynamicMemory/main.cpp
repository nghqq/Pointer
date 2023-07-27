#include<iostream>
//#include <crtdbg.h>
//#define _CRTDBG_MAP_ALLOC
#define tab "\t"
#define delimeter "\n--------------------------------------------------\n"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_back(int* arr, int& n, int value);
int* Push_front(int*& arr, int& n, int value);
int* Pop_back(int*& arr, int& n);
int* Insert(int*& arr, int& n, int value,int index);
int* Pop_front(int*& arr, int& n);
int* Pop_insert(int*& arr, int& n, int index);


void main() 
{
	setlocale(LC_ALL, "");
	int n; //Кол-во эллементов массива
	std::cout << "Введите размер массива: "; std::cin >>  n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	std::cout << "Введите число: "; std::cin >> value;
	int index;
	std::cout << "Введите индекс: "; std::cin >> index;
	arr = Push_back(arr, n, value);
	Print(arr, n);
	arr= Push_front(arr,n,value);
	Print(arr, n);
	arr = Insert(arr, n, value, index);
	Print(arr, n);
	arr=Pop_back(arr, n);
	Print(arr, n);
	arr=Pop_insert(arr, n,index);
	Print(arr, n);
	arr = Pop_front(arr, n);
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
int* Push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n+1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
		
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* Pop_back(int*& arr, int& n)
{
	int* buffer = new int[n-1];
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	n--;
	delete[]arr;
	//arr = buffer;
	
	return buffer;
}

int* Insert(int*& arr, int& n, int value,int index)
{
	int* buffer = new int[n+1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	//arr = buffer;
	buffer[index] = value;
	n++;
	return buffer;
	
	
}
int* Pop_insert(int*& arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index+1; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	//arr = buffer;
	
	n--;
	return buffer;
}
int* Pop_front(int*& arr, int& n) 
{
	int* buffer = new int[n - 1];
	for (int i = 1; i < n; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[]arr;
	n--;
	return buffer;

}




