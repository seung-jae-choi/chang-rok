//comment 
//처음에 접근할 때도 dp문제인 것을 알고 있었다. 왜 queue를 써서 접근했을까...(메모리초과 발생)

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

#define mod 1000000007

long long d;
bool map[9][9];

long long dp[100001][9];

//dp[n][~] = dp[n-1][~](갯수있는만큼)에서 이동할수 있는 곳.


void initialize() {
	map[1][2] = true; map[1][8] = true; 
	map[2][1] = true; map[2][3] = true; map[2][8] = true; 
	map[3][2] = true; map[3][4] = true; map[3][7] = true; map[3][8] = true;
	map[4][3] = true; map[4][5] = true; map[4][7] = true;
	map[5][4] = true; map[5][6] = true;
	map[6][5] = true; map[6][7] = true;
	map[7][3] = true; map[7][4] = true; map[7][6] = true; map[7][8] = true;
	map[8][1] = true; map[8][2] = true; map[8][3] = true; map[8][7] = true;
}

int main()
{
	initialize();
	cin >> d;
	memset(dp, 0, sizeof(dp));
	dp[0][1] = 1;
	for (long long i = 0; i <= d-1; i++) {
		for (int j = 1; j <= 8; j++) {
			if (dp[i][j]) {
				for (int k = 1; k <= 8; k++) {
					if (map[j][k] == true) dp[i + 1][k] = (dp[i+1][k]+dp[i][j])%mod;
				}
			}
		}
	}
	long long ans;
	
	ans = (dp[d - 1][2] + dp[d - 1][8])%mod;
	
	cout << ans;

	return 0;
}
