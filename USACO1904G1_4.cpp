#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[401], cow[401][401], range[401][401], maa[401][401];

int sort(int x, int y) {
	int ma = maa[x][y];
	int cnt = 0, sum = 0;
	for (int i = x; i <= y; i++) {
		cnt = arr[i];
		sum += ma - cnt;
	}
	return sum;
}

int go(int r, int l) {
	int ans = 999999999;
	if (r <= K - l) { return 0; }
	if (cow[r][l] != -1) { return cow[r][l]; }
	if (l == K) { return range[0][r]; }
	int cnt = 0;
	for (int i = 0; i < r; i++) {
		int temp = go(i, l + 1) + range[i + 1][r];
		if (ans > temp) {
			ans = temp;
			cnt = i;
		}
	}
	cow[r][l] = ans;
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
	for (int i = 0; i < N; i++) {
		int m = 0;
		for (int j = i; j < N; j++) {
			m = max(m, arr[j]);
			maa[i][j] = m;
		}
	}
	for (int i = 0; i < 401; i++) {
		for (int j = i; j < 401; j++) {
			range[i][j] = sort(i, j);
		}
	}
	fout << go(N - 1, 0) << endl;
}

