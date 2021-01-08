#include <iostream>
using namespace std;

int main() {

	int x = 0, min, i = 1, positionMin = 0, max, positionMax = 0;

	while (cin >> x)
	{
		if (i == 1)
		{
			min = x;
			max = x;
			positionMin = i;
		}
		if (x < min)
		{
			min = x;
			positionMin = i;
		}
		if (x >= max)
		{
			max = x;
			positionMax = i;
		}
		i++;
	}
	cout << min << "\n" << positionMin << "\n" << max << "\n" << positionMax;
	return 0;
}