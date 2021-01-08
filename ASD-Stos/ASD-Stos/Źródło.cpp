#include <iostream>
using namespace std;

int main() {
	int* stos = new int[10];
	string zadanie;
	int iteracja = 0;
	int liczba;

	while (cin >> zadanie)
	{
		if (zadanie == "+")
		{
			cin >> liczba;
			if (iteracja < 10)
			{
				stos[iteracja] = liczba;
				iteracja++;				
				cout << ":)\n";
			}
			else
			{
				cout << ":(\n";
			}
		}
		else if (zadanie == "-")
		{
			if (iteracja > 0)
			{
				cout << stos[iteracja-1] << "\n";
				iteracja--;
			}
			else
			{
				cout << ":(\n";
			}
		}
	}
	return 0;
}