#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int N;
int a[MAX], b[MAX];
//int x[MAX], y[MAX];
int score1, score2;

int count(int arr[]) {
	int ans = 0, zero = 0;
	for (int i = N; i > 0; i--) {
		arr[i] == 0 ? zero++ : ans += zero;
	}
	return ans;
}

int swap(int arr[]) {
	int k = 1;
	for (k = 1; k < N; k++) {
		if (arr[k] == 1) break;
	}
	int temp = b[1];
	b[1] = a[k];
	a[k] = temp;
}

void swapmiddle() {
	int temp = a[N];
	a[N] = b[1];
	b[1] = temp;
}

int main() {
	int n = 5;
	ifstream fin("/Users/Emerald Liu/Documents/cpp/USACO/2019/balance.txt");
	//ifstream fin("balance.in");
//	ofstream fout("balance.out");
	fin >> N;
	for (int cnt = 1; cnt <= N; cnt++) fin >> a[cnt];
	for (int cnt = 1; cnt <= N; cnt++) fin >> b[cnt];
	score1 = count(a);
	score2 = count(b);
	if (score1 != score2) swapmiddle();
	score1 = count(a);
	score2 = count(b);
	if (score1 == score2) cout << 1;
	else if (abs(score1 - score2) < N) cout << abs( N - score1 - score2); 
	else cout << max(score1, score2) / min(score1, score2);

	cout<<1;
}
