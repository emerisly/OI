#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	double need;
	double num[3];
	double price[3];
	cin >> need;
	for (int i = 0; i < 3; i++)
		cin >> num[i] >> price[i];
	int mini = min((int)(ceil(need / num[0])*price[0]), (int)(ceil(need / num[1])*price[1]));
	mini = min(mini, (int)(ceil(need / num[2])*price[2]));
	cout << mini;

	return 0;
}