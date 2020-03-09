#include <iostream>
using namespace std;

int main() {
	int day = 0;
	int over = 0;
	for (int i = 1; i <= 7; i++) {
		int a, b, sum;
		cin >> a >> b;
		sum = a + b;
		if (sum > 8 && sum > over) {
			over = sum;
			day = i;
		}
	}
	cout << day;
	
	return 0;
}