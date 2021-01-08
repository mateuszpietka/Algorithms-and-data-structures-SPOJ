#include <iostream>
using namespace std;

int main() {

	int x = 0, y = 0, i = 1, j = 0;
	do
	{
		cin >> x;
		y = x;
		do {
			cin >> x;
			i++;
			if (x <= y && x != 0) {
				y = x;
				j = i;
			}
		} while (x != 0);
	} while (x != 0);

	cout << y << "\n" << j;

	return 0;
}