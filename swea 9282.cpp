//testcase 21/22맞음. 하나 시간초과
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int t, n, m;
int map[51][51];
int d[51][51][51][51];

int sol(int r,int c,int hlen,int wlen) {
	if (hlen == 1 && wlen == 1) return 0;

	int &ret = d[r][c][hlen][wlen];
	if (ret != -1) return ret;
	ret = 987654321;
	int sum = 0;
	for (int i = r; i < r + hlen; i++) {
		for (int j = c; j < c + wlen; j++) {
			sum += map[i][j];
		}
	}

	for (int i = 1; i < hlen; i++) {
		ret = min(ret, sum + sol(r, c, i, wlen) + sol(r + i, c, hlen - i, wlen));
	}
	for (int i = 1; i < wlen; i++) {
		ret = min(ret, sum + sol(r, c, hlen, i) + sol(r, c + i, hlen, wlen - i));
	}
	return ret;
}


int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		memset(d, -1, sizeof(d));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[j][k];
			}
		}
		int ans = sol(0, 0, n, m);
		cout << "#" << i << " " << ans << "\n";
	}
	return 0;
}
