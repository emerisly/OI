#include <iostream>
using namespace std;

int swim(double left, double meter) {
	left -= meter;
	if (left < 0) {
		return 1;
	}
	else {
		return 1 + swim(left, meter*0.98);
	}
}


int main() {
	double total;
	cin >> total;
	int step = swim(total, 2);
	cout << step;
	return 0;
}