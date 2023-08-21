#include<iostream>
//#include <crtdbg.h>
//#define _CRTDBG_MAP_ALLOC
#define tab "\t"
#define delimeter "\n--------------------------------------------------\n"
#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2


template<class T>T** Allocate(const int ROWS, const int COLS);
template<class T>void Clear(T** arr, const int ROWS);

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(int** arr, const int COLS, const int ROWS);
void FillRand(double** arr, const int COLS, const int ROWS);

template<class T> void Print(T** arr, const int COLS, const int ROWS);
template<class T> void Print(T arr[], const int n);



int* Push_back(int* arr, int& n, int value);
int* Push_front(int*& arr, int& n, int value);
int* Pop_back(int*& arr, int& n);
int* Insert(int*& arr, int& n, int value,int index);
int* Pop_front(int*& arr, int& n);
int* Erase(int*& arr, int& n, int index);


template<class T>T** push_row_back(T** arr, int& ROWS, const int COLS);
template<class T>T** push_row_front(T** arr, int& ROWS, const int COLS);
template<class T>T** insert_row(T** arr, int& ROWS, const int COLS, int index);


template<class T>T** pop_row_front(T** arr, int& ROWS, const int COLS);
template<class T>T** pop_row_back(T** arr, int& ROWS, const int COLS);
template<class T>T** erase_row(T** arr, int& ROWS, const int COLS, int index);

template<class T>T** push_col_back(T** arr, int& ROWS, int& COLS);
template<class T>T** push_col_front(T** arr, int& ROWS, int& COLS);
template<class T>T** insert_col(T** arr, int& ROWS, int& COLS, int index);


template<class T>void pop_col_back(T** arr, int& ROWS, int& COLS);
template<class T>void pop_col_front(T** arr, int& ROWS, int& COLS);
template<class T>void erase_col(T** arr, int& ROWS, int& COLS, int index);



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
	
	int** arr = Allocate<int>(ROWS, COLS);
	std::cout << "Двумерный массив случайных чисел: ";
	std::cout << std::endl;
	FillRand(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << "Добавляем строку в конец: ";
	std::cout << std::endl;
	arr = push_row_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << "Добавляем строку в начало: ";
	std::cout << std::endl;
	arr = push_row_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << std::endl;
	int index;
	std::cout << "Добавляем строку по индексу: ";
	std::cout << std::endl;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << std::endl;
	arr = insert_row(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << "Удаляем первую строчку: ";
	std::cout << std::endl;
	arr = pop_row_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << "Удаляем последнюю строчку: ";
	std::cout << std::endl;
	arr = pop_row_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << "Удаляем строчку по индексу: ";
	std::cout << std::endl;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << std::endl;
	arr = erase_row(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;

	std::cout << "Добавляем столбец в конец: ";
	std::cout << std::endl;
	arr = push_col_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << std::endl;

	std::cout << "Добавляем столбец в начало: ";
	std::cout << std::endl;
	arr = push_col_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << std::endl;


	std::cout << "Добавляем столбец по индексу: ";
	std::cout << std::endl;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << std::endl;
	arr = insert_col(arr, ROWS, COLS,index);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << std::endl;


	std::cout << "Удаляем последний столбец: ";
	std::cout << std::endl;
	pop_col_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << std::endl;

	std::cout << "Удаляем первый столбец: ";
	std::cout << std::endl;
	pop_col_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << std::endl;


	std::cout << "Удаляем столбец по индексу: ";
	std::cout << std::endl;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << std::endl;
	erase_col(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	std::cout << delimeter;
	std::cout << std::endl;

	std::cout << delimeter;
	std::cout << delimeter;
	std::cout << delimeter;








	int d_ROWS = ROWS;
	int d_COLS = COLS;


	double** d_arr_2 = Allocate<double>(d_ROWS, d_COLS);
	std::cout << "Двумерный массив случайных чисел: ";
	std::cout << std::endl;
	FillRand(d_arr_2, d_ROWS, d_COLS);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << "Добавляем строку в конец: ";
	std::cout << std::endl;
	d_arr_2 = push_row_back(d_arr_2, d_ROWS, d_COLS);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << "Добавляем строку в начало: ";
	std::cout << std::endl;
	d_arr_2 = push_row_front(d_arr_2, d_ROWS, d_COLS);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << std::endl;
	std::cout << "Добавляем строку по индексу: ";
	std::cout << std::endl;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << std::endl;
	d_arr_2 = insert_row(d_arr_2, d_ROWS, d_COLS, index);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << "Удаляем первую строчку: ";
	std::cout << std::endl;
	d_arr_2 = pop_row_front(d_arr_2, d_ROWS, d_COLS);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << "Удаляем последнюю строчку: ";
	std::cout << std::endl;
	d_arr_2 = pop_row_back(d_arr_2, d_ROWS, d_COLS);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << "Удаляем строчку по индексу: ";
	std::cout << std::endl;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << std::endl;
	d_arr_2 = erase_row(d_arr_2, d_ROWS, d_COLS, index);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;

	std::cout << "Добавляем столбец в конец: ";
	std::cout << std::endl;
	d_arr_2 = push_col_back(d_arr_2, d_ROWS, d_COLS);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << std::endl;

	std::cout << "Добавляем столбец в начало: ";
	std::cout << std::endl;
	d_arr_2 = push_col_front(d_arr_2, d_ROWS, d_COLS);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << std::endl;


	std::cout << "Добавляем столбец по индексу: ";
	std::cout << std::endl;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << std::endl;
	d_arr_2 = insert_col(d_arr_2, d_ROWS, d_COLS, index);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << std::endl;


	std::cout << "Удаляем последний столбец: ";
	std::cout << std::endl;
	pop_col_back(d_arr_2, d_ROWS, d_COLS);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << std::endl;

	std::cout << "Удаляем первый столбец: ";
	std::cout << std::endl;
	pop_col_front(d_arr_2, d_ROWS, d_COLS);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << std::endl;


	std::cout << "Удаляем столбец по индексу: ";
	std::cout << std::endl;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << std::endl;
	erase_col(d_arr_2, d_ROWS, d_COLS, index);
	Print(d_arr_2, d_ROWS, d_COLS);
	std::cout << delimeter;
	std::cout << std::endl;







	Clear(d_arr_2, ROWS);
	Clear(arr, ROWS);

}

template<class T>
T** Allocate(const int ROWS, const int COLS) 
{
	T** arr = new T * [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = new T[COLS] {};
	}
	return arr;
}

template<class T>
void Clear(T** arr, const int ROWS) 
{
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
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 10000;
		*(arr + i) /= 100;
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
void FillRand(double** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}

template<class T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << std::endl;
}

template<class T>
void Print(T** arr, const int ROWS, const int COLS)
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
template<class T>
T* Pop_front(T*& arr, int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 1; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[]arr;
	n--;
	return buffer;
}

template<class T>
T** push_row_back(T** arr, int& ROWS, const int COLS)
{
	T** buffer = new T* [ROWS + 1] {};
	for (int i = 0; i < ROWS; i++)
		buffer[i] = arr[i];
	delete[]arr;
	buffer[ROWS] = new T[COLS] {};
	ROWS++;
	return buffer;
}


template<class T>
T** push_row_front(T** arr, int& ROWS, const int COLS)
{
	T** buffer = new T* [ROWS + 1] {};
	for (int i = 0; i < ROWS; i++)
		buffer[i + 1] = arr[i];
	delete[]arr;
	buffer[ROWS-ROWS] = new T[COLS] {};
	ROWS++;
	return buffer;
}

template<class T>
T** insert_row(T** arr, int& ROWS, const int COLS, int index)
{
	T** buffer = new T* [ROWS + 1] {};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < ROWS; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[index] = new T[COLS] {};
	ROWS++;
	return buffer;
}

template<class T>
T** pop_row_front(T** arr, int& ROWS, const int COLS)
{
	T** buffer = new T* [ROWS - 1] {};
	for (int i = 1; i < ROWS; i++)
		buffer[i - 1] = arr[i];
	delete[]arr;
	buffer[ROWS] = new T[COLS] {};
	ROWS--;
	return buffer;
}
template<class T>
T** pop_row_back(T** arr, int& ROWS, const int COLS)
{
	T** buffer = new T* [ROWS - 1] {};
	for (int i = 0; i < ROWS-1; i++)
		buffer[i] = arr[i];
	delete[]arr;
	buffer[ROWS] = new T[COLS] {};
	ROWS--;
	return buffer;
}
template<class T>
T** erase_row(T** arr, int& ROWS, const int COLS, int index)
{
	T** buffer = new T* [ROWS - 1] {};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index+1; i < ROWS; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[]arr;
	ROWS--;
	return buffer;
}

template<class T>
T** push_col_back(T** arr, int& ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS + 1] {};
		for (int j = 0; j < COLS; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS++;
	return arr;
}

template<class T>
T** push_col_front(T** arr, int& ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS + 1] {};
		for (int j = 0; j < COLS; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS++;
	return arr;
}

template<class T>
T** insert_col(T** arr, int& ROWS, int& COLS, int index) 
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS + 1] {};
		for (int j = 0; j < COLS; j++)
		{
			if (j < index)
				buffer[j] = arr[i][j];
			else
				buffer[j + 1] = arr[i][j];
		}
	delete[] arr[i];
	arr[i] = buffer;
	}
	COLS++;
	return arr;
}

template<class T>
void  pop_col_back(T** arr,  int& ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS] {};
		for (int j = 0; j < COLS; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS--;
	
}

template<class T>
void  pop_col_front(T** arr, int& ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS] {};
		for (int j = 0; j < COLS; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS--;

}

template<class T>
void erase_col(T** arr, int& ROWS, int& COLS, int index)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS] {};
		for (int j = 0; j < COLS; j++)
		{
			if (j < index)
				buffer[j] = arr[i][j];
			else
				buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS--;
	
}










