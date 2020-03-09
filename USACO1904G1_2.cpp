#include <bits/stdc++.h>
using namespace std;

int arr[405], cow[405][405];
int N, K, INF = 99999999;

int sort(int x, int y) {
	int ma = 0;
	for (int i = x; i <= y; i++) {
		if (ma < arr[i]) ma = arr[i];
	}
	int cnt = 0, sum = 0;
	for (int i = x; i <= y; i++) {
		if (cnt + arr[i] > ma) cnt = arr[i];
		else cnt += arr[i];
		sum += ma - cnt;
	}
	return sum;
}
int GO(int r, int l) {
	int ans = INF;
	if (cow[r][l] != -1) { return cow[r][l]; }
	if (l == K) { return sort(0, r); }
	for (int i = 0; i < r; i++) {
		ans = min(ans, GO(i, l + 1) + sort(i + 1, r));
	}
	return ans;
}
int main() {
	//ifstream fin("/Users/Emerald Liu/Documents/cpp/USACO/2019/Snake.txt");
	ifstream fin("snakes.in");
	ofstream fout("snakes.out");
	fin >> N >> K;
	memset(cow, -1, sizeof cow);
	for (int i = 0; i < N; i++) {
		fin >> arr[i];
	}
	fout << GO(N - 1, 0) << endl;
}
