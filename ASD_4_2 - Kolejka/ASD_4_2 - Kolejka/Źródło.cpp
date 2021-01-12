#include <iostream>
using namespace std;

int main() {
	int* stos = new int[10];
	string decyzja;
	int iteracja = 0;
	int liczba;

	while (cin >> decyzja)
	{
		if (decyzja == "Enqueue")
		{
			cin >> liczba;
			if (iteracja < 10)
			{
				stos[iteracja] = liczba;
				iteracja++;
				cout << "--->\n"; 
				
			}
			else
			{
				cout << "Error: queue is full\n";
			}
		}
		else if (decyzja == "Dequeue")
		{
			if (iteracja > 0)
			{
				cout << stos[0] << "\n";		
				for (int i = 0; i < iteracja; i++)
				{
					stos[i] = stos[i + 1];
				}
				iteracja--;
			}
			else
			{
				cout << "Error: queue is empty\n";
			}
		}
		else if (decyzja == "Print")
		{
			if (iteracja > 0)
			{		
				cout << "Print: ";
				for (int i = 0; i < iteracja; i++)
				{
					cout << stos[i] << " ";
				}
				cout << "\n";
			}
			else
			{
				cout << "Print: Queue is empty\n";
			}
		}
	}
	return 0;
}