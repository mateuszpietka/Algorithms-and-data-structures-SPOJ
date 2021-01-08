#include <iostream>
using namespace std;

int main() {

	int x = 0, y = 0;
	do
	{
		cin >> x;
		if (x > y) {
			y = x;
		}
	} while (x != 0);
	cout << y;
	return 0;
}