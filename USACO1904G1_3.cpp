using namespace std;
#include <bits/stdc++.h>

int cow[405];
int sort(int a, int b, int K) {
	int cnt = 0, sum = 0;
	for (int i = a; i <= b; i++) {
		cnt = cow[i];
		sum += K - cnt;
	}
	return sum;
}
int main() {
	//ifstream fin("/Users/Emerald Liu/Documents/cpp/USACO/2019/Snake.txt");
	ifstream fin ("snakes.in");
	ofstream fout("snakes.out");
	int N = 0, K = 0;
	fin >> N >> K;
	K++;

	for (int i = 0; i < N; i++) {
		fin >> cow[i];
	}
	int go[K][N], goMax[N][N], range[N][N];

	for (int i = 0; i < N; i++) {
		int maxx = 0;
		for (int j = i; j < N; j++) {
			maxx = max(maxx, cow[j]);
			goMax[i][j] = maxx;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			range[i][j] = sort(i, j, goMax[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= j) {
				go[i][j] = 0;
				continue;
			}
			if (i == 0)
				go[i][j] = range[0][j];
			else {
				int ans = 99999999;
				for (int z = 0; z < j; z++) {
					ans = min(ans, (go[i - 1][z] + range[z + 1][j]));
				}
				go[i][j] = ans;
			}
		}
	}
	
	fout << go[K - 1][N - 1] <<endl;
}
