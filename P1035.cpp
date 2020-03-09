#include <iostream>
using namespace std;


int add(double all,double num) {
	double left = all;
	left -= 1.0 / num;
	if (left<0) {
		return num;
	}
	else {
		return add(left, num + 1);
	}
}

int main() {
	double sum, K;
	cin >> K;
	sum = add(K, 1);
	cout << sum;
	return 0;
}
