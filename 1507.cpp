#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
int d[21][21];
int w[21][21];
void initialize();
void input();
int solv();
int calc();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	input();
	initialize(); // 모든 거리 연결
	cout << solv();
	return 0;
}

void initialize()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) w[i][j] = 0;
			else w[i][j] = 1;
		}
}
void input()
{
	for(int i=1;i <= n;i++)
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
}
int solv() {
	int ans;
	for(int k=1;k<=n;k++)
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) {
				if (i == k || j == k) continue;
				if (d[i][j] == d[i][k] + d[k][j])
					w[i][j] = 0;
				if (d[i][j] > d[i][k] + d[k][j]) // 불가능
					return -1;
			}
	ans = calc();
	return ans;
}
int calc() {
	int cnt(0);
	for(int i=1;i<=n;i++)
		for (int j = i; j <= n; j++) { // w[1][2], w[2][1] 고려
			if (w[i][j] == 1)
				cnt += d[i][j];
		}
	return cnt;
}
