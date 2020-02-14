#include<iostream>
using namespace std;

int n;
int w[500][500];
int d[500][500]; // d[i][j] -> i는 층,j는 왼,오른쪽인지 거리 최대값
int result(0);
void max();
int Max(int x, int y);

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> w[i][j];
		}
	}
	max();
	
	cout << result;
	
	return 0;
}

void max()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == 1 && j == 1) d[1][1] = w[1][1];
			else if(j==1) d[i][j] = d[i - 1][j] + w[i][j];
			else if(i == j) d[i][j] = d[i - 1][j - 1] + w[i][j];
			else {
				d[i][j] = Max(d[i - 1][j - 1], d[i - 1][j]) + w[i][j];
			}
			if (result < d[i][j]) result = d[i][j];
		}
	}
}

int Max(int x, int y) {
	if (x > y) return x;
	else
		return y;
}
