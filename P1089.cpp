#include <iostream>
using namespace std;

int main() {
	int keep=0;
	int have=0;
	bool oops=false;
	int m;

	for (int month = 1; month <= 12; month++) {
		int plan;
		int give;
		cin >> plan;
//		cout << "\t" << month << " " << plan << endl;
		have += 300;
		have -= plan;
		if (have < 0 && !oops) {
			oops = true;
			m = month;
		}
		give = have / 100;
		keep += give * 100;
		have -= give * 100;
//		cout << "keep: " << keep;
//		cout << "\nhave: " << have << "\n\n";
	}

	if (oops) {
		cout << "-" << m << endl;
	}else {
		cout << keep * 1.2 + have << "\n";
	}
	return 0;
}