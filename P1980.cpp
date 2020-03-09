#include<iostream>
#include<string>

using namespace std;

int main() {
	int n;
	string a, b;
	int sum=0;

	cin >> n >> b;

	for (int i = 1; i <= n; i++) {
		a += to_string(i);
	}

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == b[0]) {
			sum++;
		}
	}

	cout << sum;


	return 0;
}