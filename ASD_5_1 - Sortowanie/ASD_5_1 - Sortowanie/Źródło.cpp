#include <iostream>
using namespace std;

void Sortowanie(int* tab, int lewy, int prawy)
{
	int i, j, piwot;

	i = (lewy + prawy) / 2;
	piwot = tab[i]; tab[i] = tab[prawy];
	for (j = i = lewy; i < prawy; i++)
		if (tab[i] < piwot)
		{
			swap(tab[i], tab[j]);
			j++;
		}
	tab[prawy] = tab[j]; tab[j] = piwot;
	if (lewy < j - 1)  Sortowanie(tab, lewy, j - 1);
	if (j + 1 < prawy) Sortowanie(tab, j + 1, prawy);
}


void wyswietlenie(int tab[], int j) 
{
	for (int i = 0; i < j; i++)
	{
		cout << tab[i] << "\n";
	}
}

int main() {
	int liczba, iteracja = 0;
	int* tab = new int[100000];
	while(cin >> liczba)
	{
		tab[iteracja] = liczba;
		iteracja++;
	}

	Sortowanie(tab, 0, iteracja-1);
	wyswietlenie(tab,iteracja);
	return 0;
}