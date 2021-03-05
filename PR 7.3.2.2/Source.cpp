// Lab_7_3-1.cpp
// Обухов Віктор
// Лабораторна робота № 7.3.2.2
// Опрацювання динамічних багатовимірних масивів (рекурсія)
// Варіант 7

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);

	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
int Sum2(int** a, const int colCount, int S, int rowNo, int colNo)
{
	S += a[rowNo][colNo];

	if (colNo < colCount - 1)
		Sum2(a, colCount, S, rowNo, colNo + 1);
	else
		return S;
}
int SearchNegative(int** a, const int colCount, int rowNo, int colNo, int x)
{
	if (a[rowNo][colNo] < 0)
		x = 1;

	if (colNo < colCount - 1)
		SearchNegative(a, colCount, rowNo, colNo + 1, x);
	else
		return x;

}
int Sum(int** a, const int rowCount, const int colCount, int S, int rowNo)
{
	int x = 0;
	x = SearchNegative(a, colCount, rowNo, 0, x);

	if (x > 0)
		S = Sum2(a, colCount, S, rowNo, 0);

	if (rowNo < rowCount - 1)
		Sum(a, rowCount, colCount, S, rowNo + 1);
	else
		return S;
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = -5;
	int High = 25;

	int rowCount, colCount;

	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** arr = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		arr[i] = new int[colCount];

	Create(arr, rowCount, colCount, Low, High, 0, 0);
	cout << endl;
	Print(arr, rowCount, colCount, 0, 0);

	int S = Sum(arr, rowCount, colCount, 0, 0);

	cout << "Sum = " << S << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}