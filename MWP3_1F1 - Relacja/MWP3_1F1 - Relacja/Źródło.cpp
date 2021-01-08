#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pary {
public:
	int a, b;
	Pary(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
};

int Zwrotnosc(int** tab, int n)
{
	for (int i = 0; i < n; i++) {
		if (tab[i][i] == 0)
		{
			return 0;
		}
	}
	return 1;
}

int Przeciwzwrotnosc(int** tab, int n)
{
	for (int i = 0; i < n; i++) {
		if (tab[i][i] == 1)
		{
			return 0;
		}
	}
	return 1;
}

int Symetria(int** tab, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tab[i][j] != tab[j][i])
			{
				return 0;
			}
		}

	}
	return 1;
}

int Antysymetria(int** tab, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tab[i][j] == 1 && tab[j][i] == 1)
			{
				return 0;
			}
		}
	}
	return 1;
}


int Spojnosc(int** tab, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tab[i][j] == 0 && tab[j][i] == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

int Przechodniosc(int** tab, int n)
{
	int** tab2 = new int* [n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		tab2[i] = new int[n + 1];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int s = 0;
			for (int k = 0; k < n; k++)
			{
				s += tab[i][k] * tab[k][j];
				tab2[i][j] = s;
				if (tab2[i][j] > 1)
				{
					tab2[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] != tab2[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}


int main() {
	int a, b, wielkosc = 0;
	int warunek = 0;
	vector<Pary> para;
	while (cin >> a >> b)
	{
		if (a > wielkosc)
		{
			wielkosc = a - 1;
		}
		if (b > wielkosc)
		{
			wielkosc = b - 1;
		}
		Pary p = Pary(a, b);
		para.push_back(p);
	}

	int** tab = new int* [wielkosc + 1];

	for (int i = 0; i < wielkosc + 1; i++)
	{
		tab[i] = new int[wielkosc + 1];
		for (int j = 0; j < wielkosc + 1; j++)
		{
			tab[i][j] = 0;
		}
	}

	for (int i = 0; i < para.size(); i++)
	{
		Pary p = para[i];
		tab[p.a - 1][p.b - 1] = 1;
	}

	int z = 0, pz = 0, s = 0, as = 0, p = 0, sp = 0;

	if (Zwrotnosc(tab, wielkosc))
	{
		z = 1;
		cout << "Z ";
	}
	if (Przeciwzwrotnosc(tab, wielkosc))
	{
		pz = 1;
		cout << "PZ ";
	}
	if (Symetria(tab, wielkosc))
	{
		s = 1;
		cout << "S ";
	}
	if (Antysymetria(tab, wielkosc))
	{
		as = 1;
		cout << "AS ";
	}
	if (Przechodniosc(tab, wielkosc))
	{
		p = 1;
		cout << "P ";
	}
	if (Spojnosc(tab, wielkosc))
	{
		sp = 1;
		cout << "SP ";
	}

	warunek = z + pz + s + as + p + sp;
	if (warunek == 0)
	{
		cout << "X";
		return 0;
	}
	if (warunek != 0)
	{
		int rr = 0, rpl = 0, rpcz = 0;
		cout << "\n";
		if (z == 1 && s == 1 && p == 1)
		{
			rr = 1;
			cout << "RR ";
		}
		if (z == 1 && p == 1 && as == 1 && sp == 1)
		{
			rpl = 1;
			cout << "RPL ";
		}
		if (rpl == 0 && z == 1 && p == 1 && as == 1)
		{
			rpcz = 1;
			cout << "RPCz";
		}
		if (rr == 0 && rpl == 0 && rpcz == 0)
		{
			cout << "X";
		}
	}
	return 0;
}