#include<iostream>
#define tab "\t"
#define delimeter "\n--------------------------------------------------\n"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main() 
{
	setlocale(LC_ALL, "");
	int n; //���-�� ���������� �������
	std::cout << "������� ������ �������: "; std::cin >>  n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
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
