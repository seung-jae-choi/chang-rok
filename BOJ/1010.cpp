#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;



int n,m,test;
int d[31][31];



int main()
{
	cin >> test;
	memset(d, 0, sizeof(d));
	for (int j = 1; j < 31; j++) {
		d[1][j] = j;
	}
	for (int x = 2; x < 31; x++) {
		for (int y = x; y < 31; y++) {
			for (int k = y - 1; k >= x - 1; k--) {
				d[x][y] += d[x - 1][k];
			}
		}
	}
	for (int i = 0; i < test; i++) {
		cin >> n >> m;
		
		cout << d[n][m] << "\n";
	}
	return 0;
}
