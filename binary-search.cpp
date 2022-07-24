// binary-search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <new>
#include <limits>
using namespace std;

int integerInput();
int getSize();
int* binarySearch(int, int, int[]);

int main()
{
    int size, *arr;

	cout << "\t\t|----------Program to binary search from given range of whole numbers----------|";

    cout << endl << "Please enter the range: ";
	size = getSize();

	arr = new (nothrow) int[size];

	if (arr == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please start the application again.";
		exit(0);
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
		cout << " " << arr[i];
	}

	cout << endl << "Enter the element you want to find: ";
	int* d = binarySearch(integerInput(), size, arr);

	if (d == nullptr)
		cout << endl << "Data not found!";
	else
		cout << endl << "Data found at address: " << d;

    return 0;
}

int integerInput()
{
	int n;

	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid integer input! Please try again with correct input: ";
	}

	return n;
}

int getSize()
{
	int size = integerInput();

	if (size <= 0)
	{
		cout << endl << "Invalid range! Please enter again: ";
		size = getSize();
		return size;
	}

	return size;
}

int* binarySearch(int d, int size, int arr[])
{
	if (d < arr[0] || d > arr[size - 1])
		return nullptr;
	if (arr[0] == d)
		return &arr[0];
	if (arr[size - 1] == d)
		return &arr[size - 1];

	int start = 0, end = size, mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (d == arr[mid])
			return &arr[mid];
		if (d < mid)
			end = mid - 1;
		if (d > mid)
			start = mid + 1;
		
	}

	return nullptr;
}