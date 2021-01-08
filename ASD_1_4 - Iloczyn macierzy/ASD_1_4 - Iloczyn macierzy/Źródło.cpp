#include <iostream>

using namespace std;

int main() {

	int kolumny, wiersze;
	cin >> wiersze;
	cin >> kolumny;
	int** macierz = new int* [wiersze];

	for (int i = 0; i < wiersze; i++)
	{
		macierz[i] = new int[kolumny];
		for (int j = 0; j < kolumny; j++)
		{
			cin >> macierz[i][j];
		}
	}

	int** macierzTransponowana = new int* [kolumny];
	for (int i = 0; i < kolumny; i++)
	{
		macierzTransponowana[i] = new int[wiersze];
		for (int j = 0; j < wiersze; j++)
		{
			macierzTransponowana[i][j] = macierz[j][i];
		}
	}

	int s;
	int** iloczyn = new int* [kolumny];
	for (int i = 0; i < kolumny; i++)
	{
		iloczyn[i] = new int[kolumny];
		for (int j = 0; j < kolumny; j++)
		{
			s = 0;
			for (int k = 0; k < wiersze; k++)
			{
				s += macierzTransponowana[i][k] * macierz[k][j];
				iloczyn[i][j] = s;

			}
		}
	}

	for (int i = 0; i < kolumny; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			cout << iloczyn[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}