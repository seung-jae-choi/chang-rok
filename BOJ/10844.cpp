#include<iostream>
using namespace std;
#define M 1000000000

int n;
int d[101][10];

//d[n] -> 1-8까진 2배씩, 0,9는 1가지
//d[2]= 8*2+1;

int main()
{
	cin >> n;
	
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				d[i][0] = d[i - 1][1] % M;
			}
			else if (j == 9) {
				d[i][9] = d[i - 1][8] % M;
			}
			else {
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % M;
			}
		}
	}
	int sum(0);
	for (int i = 1; i < 10; i++) {
		sum =(sum+d[n][i])%M;
	}
	cout << sum%M;
	return 0;
}
