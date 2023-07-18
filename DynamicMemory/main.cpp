#include<iostream>
#define tab "\t"
#define delimeter "\n--------------------------------------------------\n"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Add(int* arr, const int n);

void main() 
{
	setlocale(LC_ALL, "");
	int n; //���-�� ���������� �������
	std::cout << "������� ������ �������: "; std::cin >>  n;
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
		//��������� � ��������� ������� ����� ���������� ���������� � �������� �������������
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
	std::cout << "������� �����:"; std::cin >> *temp_arr;
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i]<< tab;
		std::cout << *temp_arr;
		
	}
	std::cout << std::endl;
}

