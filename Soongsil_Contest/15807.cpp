#include<iostream>

using namespace std;

int n, p, x, y;
int dp[2][3005][3005];
int dx[2] = { -1,1 };
int dy[2] = { 1,1 };

int cv(int in) {
	return in + 1501;
}

int solv(int ny, int nx) {
	int ret = 0;
	for (int i = 0; i <= 3001; i++) {
		ret += dp[0][ny][i];
		if (i == nx) return ret;
		ret -= dp[1][ny][i];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		for (int j = 0; j < 2; j++) {
			dp[j][cv(y)][cv(x)]++;
		}
	}

	for (int i = 1; i <= 3001; i++) {
		dp[0][i + 1][0] += dp[0][i][0];
		for (int j = 1; j <= 3001; j++) {
			for (int k = 0; k < 2; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				dp[k][ny][nx] += dp[k][i][j];
			}
		}
	}
	cin >> p;
	for (int i = 0; i < p; i++) {
		cin >> x >> y;
		cout << solv(cv(y), cv(x)) << "\n";
	}
	
	return 0;
}
