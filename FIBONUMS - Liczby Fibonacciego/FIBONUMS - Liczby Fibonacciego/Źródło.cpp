#include<iostream>
#include<cstdlib>
#include <unordered_map>

using namespace std;

unordered_map<unsigned long long, unsigned long long> Fibona;
unsigned long long fib(unsigned long long n)
{
	if (n < 2) return 1;
	if (Fibona.find(n) != Fibona.end()) return Fibona[n];
	Fibona[n] = (fib((n + 1) / 2) * fib(n / 2) + fib((n - 1) / 2) * fib((n - 2) / 2)) % 1000000007;
	return Fibona[n];
}


int main()
{
	int n;
	unsigned long long x;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		cout << fib(x - 1) << "\n";
	}
	return 0;
}