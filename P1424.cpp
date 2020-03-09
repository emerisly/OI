#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long a, b, ans;
	cin >> a >> b;

	for (long i = 0; i < b; i++) {
		if (a != 6 && a != 7) {
			ans += 250;
		}
		if (a == 7) {
			a = 1;
		}
		else {
			a++;
		}
	}

	cout << ans;

	return 0;
}