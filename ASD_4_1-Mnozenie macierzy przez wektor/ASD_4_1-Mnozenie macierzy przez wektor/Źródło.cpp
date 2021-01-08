#include <iostream>
#include<iomanip>
using namespace std;

int main() {

	int n, m;
	cin >> n;
	cin >> m;
	double** tabela = new double* [m];

	for (int i = 0; i < m; i++)
	{
		tabela[i] = new double[n + 1];
		for (int j = 0; j < n + 1; j++)
		{
			cin >> tabela[i][j];
		}
	}
	double** wektor = new double* [m];
	for (int i = 0; i < m; i++)
	{
		wektor[i] = new double[1];
		for (int j = 0; j < n + 1; j++)
		{
			if (j == n) {
				wektor[i][0] = tabela[i][j];
			}
		}
	}
	double** macierzTransponowana = new double* [n];
	for (int i = 0; i < n; i++)
	{
		macierzTransponowana[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			macierzTransponowana[i][j] = tabela[j][i];
		}
	}
	double s;
	double** tab4 = new double* [n];
	for (int i = 0; i < n; i++)
	{
		tab4[i] = new double[1];
		for (int j = 0; j < 1; j++)
		{
			s = 0;
			for (int k = 0; k < m; k++)
			{
				s += macierzTransponowana[i][k] * wektor[k][j];
				tab4[i][j] = s;
			}
			cout << fixed << setprecision(7) << tab4[i][j] << " ";
		}
	}
	return 0;
}