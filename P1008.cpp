#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string all = "";
	int a, b, c;
	for (int i = 100; i <= 333; i++) {
		a = i;
		b = i * 2;
		c = i * 3;
		all = to_string(a)+to_string(b)+to_string(c);
		bool have = true;
		for (int j = 1; j < 10; j++) {
			string ch = to_string(j);
			if (have == true && all.find(ch) == string::npos) {
				have = false;
				break;
			}
		}
		if (have) {
			cout << a << " " << b << " " << c << endl;
		}
		
	}
	return 0;
}
