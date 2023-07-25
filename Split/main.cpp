#include<iostream>

void FillRand(int arr[], const int n);
void Print(int arr[],const int n);





void main() 
{
	setlocale(LC_ALL, "");

	const int n = 10;
	int arr[n];
	int count = 0;
	

	FillRand(arr, n);
	Print(arr, n);
	

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			count++;
		}
	}
	
	std::cout << count << "\t";
	std::cout << std::endl;
	std::cout << n-count << "\t";
	std::cout << std::endl;

	int* even = new int[count];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) 
		{
			
			
				even[j++] = arr[i];
				

			
		
		}
	}
	std::cout << " четные числа " << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << even[i] << "\t";
	}
	std::cout << std::endl;

	int* odd = new int[n-count];
	int g = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{


			odd[g++] = arr[i];
			



		}
	}
	std::cout << " нечетные числа " << std::endl;
	for (int i = 0; i < n-count; i++)
	{
		std::cout << odd[i] << "\t";
	}

	delete[]even, odd;
}


void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 33;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}





