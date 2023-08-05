#include<iostream>
//#include <crtdbg.h>
//#define _CRTDBG_MAP_ALLOC
#define tab "\t"
#define delimeter "\n--------------------------------------------------\n"
#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int COLS, const int ROWS);

void Print(int arr[], const int n);
void Print(int** arr, const int COLS, const int ROWS);

int* Push_back(int* arr, int& n, int value);


int* Push_front(int*& arr, int& n, int value);
int* Pop_back(int*& arr, int& n);
int* Insert(int*& arr, int& n, int value,int index);
int* Pop_front(int*& arr, int& n);
int* Erase(int*& arr, int& n, int index);


int** push_row_back(int** arr, int& ROWS, const int COLS);
int** push_row_front(int** arr, int& ROWS, const int COLS);
int** insert_row(int** arr, int& ROWS, const int COLS, int index);


int** pop_row_front(int** arr, int& ROWS, const int COLS);
int** pop_row_back(int** arr, int& ROWS, const int COLS);
int** erase_row(int** arr, int& ROWS, const int COLS, int index);


void main()
{
	setlocale(LC_ALL, "");
#ifndef DYNAMIC_MEMORY_1
	int n; //Кол-во эллементов массива
	std::cout << "Введите размер массива: "; std::cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	std::cout << "Введите число: "; std::cin >> value;
	int index;
	std::cout << "Введите индекс: "; std::cin >> index;
	arr = Push_back(arr, n, value);
	Print(arr, n);
	arr = Push_front(arr, n, value);
	Print(arr, n);
	arr = Insert(arr, n, value, index);
	Print(arr, n);
	arr = Pop_back(arr, n);
	Print(arr, n);
	arr = Pop_front(arr, n);
	Print(arr, n);
	arr = Erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
	//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	//_CrtDumpMemoryLeaks();


#endif // !DYNAMIC_MEMORY_1



	int ROWS;
	int COLS;

	std::cout << "Введите кол-во строк: "; std::cin >> ROWS;
	std::cout << "Введите кол-во элементов в строке: "; std::cin >> COLS;

	int** arr = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = new int[COLS] {};
	}
	FillRand(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	arr = push_row_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	arr = push_row_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << std::endl;
	int index;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << std::endl;
	arr = insert_row(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	arr = pop_row_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	arr = pop_row_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << std::endl;
	arr = erase_row(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;

	
	for (int i = 0; i < ROWS; i++)
	{
		delete arr[i];
	}
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

void FillRand(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
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
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];

	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* Pop_back(int*& arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	n--;
	delete[]arr;
	//arr = buffer;

	return buffer;
}

int* Insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
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
int* Erase(int*& arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index + 1; i < n; i++)
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
		buffer[i - 1] = arr[i];
	}
	delete[]arr;
	n--;
	return buffer;
}

int** push_row_back(int** arr, int& ROWS, const int COLS)
{
	int** buffer = new int* [ROWS + 1] {};
	for (int i = 0; i < ROWS; i++)
		buffer[i] = arr[i];
	delete[]arr;
	buffer[ROWS] = new int[COLS] {};
	ROWS++;
	return buffer;
}



int** push_row_front(int** arr, int& ROWS, const int COLS)
{
	int** buffer = new int* [ROWS + 1] {};
	for (int i = 0; i < ROWS; i++)
		buffer[i+1] = arr[i];
	delete[]arr;
	buffer[ROWS-ROWS] = new int[COLS] {};
	ROWS++;
	return buffer;
}

int** insert_row(int** arr, int& ROWS, const int COLS, int index)
{
	int** buffer = new int* [ROWS + 1] {};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < ROWS; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[index] = new int[COLS] {};
	ROWS++;
	return buffer;
}

int** pop_row_front(int** arr, int& ROWS, const int COLS)
{
	int** buffer = new int* [ROWS - 1] {};
	for (int i = 1; i < ROWS; i++)
		buffer[i - 1] = arr[i];
	delete[]arr;
	buffer[ROWS] = new int[COLS] {};
	ROWS--;
	return buffer;
}
int** pop_row_back(int** arr, int& ROWS, const int COLS)
{
	int** buffer = new int* [ROWS - 1] {};
	for (int i = 0; i < ROWS-1; i++)
		buffer[i] = arr[i];
	delete[]arr;
	buffer[ROWS] = new int[COLS] {};
	ROWS--;
	return buffer;
}
int** erase_row(int** arr, int& ROWS, const int COLS, int index)
{
	int** buffer = new int* [ROWS - 1] {};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index+1; i < ROWS; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[]arr;
	ROWS--;
	return buffer;
}





