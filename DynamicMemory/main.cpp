#include<iostream>
#define tab "\t"
#define delimeter "\n--------------------------------------------------\n"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Add(int* arr, const int n);

void main() 
{
	setlocale(LC_ALL, "");
	int n; //Кол-во эллементов массива
	std::cout << "Введите размер массива: "; std::cin >>  n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	Add(arr, n);

	delete[] arr;
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
void Add(int* arr, const int n)
{

	int* temp_arr = new int[1];
	
	for (int i = 0; i < n + *temp_arr; i++)
	{
		std::cout << arr[i]<< tab;
		std::cout << "Введите число:"; std::cin >> *temp_arr;
		
	}
	std::cout << std::endl;
}

