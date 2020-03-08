#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[100001];
int mmax;

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}
	mmax=dp[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] > 0 && dp[i - 1] + dp[i] > 0) {
			dp[i] = dp[i - 1] + dp[i];
		}
		if (mmax < dp[i]) {
			mmax = dp[i];
		}
	}
	cout << mmax;
	return 0;
}
