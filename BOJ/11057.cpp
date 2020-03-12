#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int n;
long long d[1001][10];



int main()
{
	cin >> n;
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j;k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= 10007;
			}
		}
	}
	long long sum(0);
	long long tmp;
	for (int i = 0; i < 10; i++) {
		tmp = (sum+d[n][i])%10007;
		sum = tmp;
	}
	cout << sum % 10007;
	return 0;
}
