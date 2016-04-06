#include <iostream>
using namespace std;
const int N = 25;

void Display(int**, int);
void FreeMemory(int**, int);
int MaxElementInMatrix(int**, int, int, int);
int** AllocMemory(int);
void EnterMatrix(int**, int);
int EnterDemention(int);
void ChangeMatrix(int**, int**, int);

int main()
{
	int n = EnterDemention(N);
	cout << "The first matrix is: " << endl;
	int **a = AllocMemory(n);
	cout << "Enter elements in your matrix: " << endl;
	EnterMatrix(a, n);
	system("cls");
	cout << "Matrix : " << endl;
	Display(a, n);

	int **b = AllocMemory(n);
	cout << endl << "The change matrix is: " << endl;
	ChangeMatrix(a, b, n);
	Display(b, n);
	FreeMemory(a, n);
	FreeMemory(b, n);
	system("pause");
	return 0;
}

void Display(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(7);
			cout << a[i][j];
		}
		cout << endl;
	}
}

void FreeMemory(int** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}

int MaxElementInMatrix(int** a, int n, int k, int m)
{
	int max = a[k][m];
	if (k != m)
	{
		if (m > k)
		{
			for (int i = 0; i < n && i + m - k < n; i++)
			{
				for (int j = i + m - k; j<n; j++)
				{
					if (a[i][j] > max) max = a[i][j];
				}
			}
		}
		else
		{
			for (int i = n - 1;i + m - k; i--)
			{
				for (int j = 0; j <=i + m - k; j++)
				{
					if (a[i][j] > max) max = a[i][j];
				}
			}
		}
	}
	else max = max;
	return max;
}

int** AllocMemory(int n)
{
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	return a;
}

void EnterMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << (i + 1) << "][" << (j + 1) << "]=";
			cin >> a[i][j];
		}
	}
}

int EnterDemention(int n)
{
	while (true)
	{
		cout << "Please, enter size of matrix: ";
		cin >> n;
		system("cls");
		if ((n > 1) && (n < N)) break;
		cout << "Error! Please, enter other size or value " << endl;
	}
	return n;
}

void ChangeMatrix(int** a, int**b, int n)
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		b[i][j] = MaxElementInMatrix(a, n, i, j);

}
