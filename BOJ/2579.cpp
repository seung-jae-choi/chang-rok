#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int t,n;
int s[301];
int dp[301];
//dp[n]=s[n]+s[n-1]+dp[n-3];
//dp[n]=s[n]+dp[n-2]

int main()
{
	
		cin >> n;
		memset(s, 0, sizeof(s));
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= n; j++) {
			cin >> s[j];
		}
		dp[0] = 0; dp[1] = s[1]; dp[2] = dp[1] + s[2];
		for (int j = 3; j <= n; j++) {
			dp[j] = max(s[j] + s[j - 1] + dp[j - 3], s[j] + dp[j - 2]);
		}
		cout << dp[n] << "\n";
	
	return 0;
}
