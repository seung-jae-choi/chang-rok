#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int d[2][100001];
int a[2][100001];
int n,test;

int main()
{
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		for (int y = 0; y < 2; y++) {
			for (int x = 1; x <= n; x++) {
				cin >> a[y][x];
			}
		}
		d[0][0] = d[1][0] = 0;
		d[0][1] = a[0][1];
		d[1][1] = a[1][1];
		for (int j = 2; j <= n; j++) {
			d[0][j] = max(d[1][j - 2], d[1][j - 1]) + a[0][j];
			d[1][j] = max(d[0][j - 2], d[0][j - 1]) + a[1][j];
		}
		cout << max(d[0][n], d[1][n]) <<"\n";
	}
	return 0;
}
