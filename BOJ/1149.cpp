#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int m[1001][3];
int dp[1001][3];
int answer;
//dp[n]=dp[n-1]+m[n](min)

//dp[n][0]=min(dp[n-1][1],dp[n-1][2])+m[n][0]
//dp[n][1]=min(dp[n-1][0],dp[n-1][2])+m[n][1]
//dp[n][2]=min(dp[n-1][0],dp[n-1][1])+m[n][2]

int main()
{
	cin >> n;
	memset(m, 0, sizeof(m));
	dp[0][0] = dp[0][1] = dp[0][2] = m[0][0] = m[0][1] = m[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> m[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + m[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + m[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + m[i][2];
	}
	answer = min(min(dp[n][0], dp[n][1]), dp[n][2]);
	cout << answer << "\n";

	return 0;
}
