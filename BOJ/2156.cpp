#include<iostream>
#include<algorithm>
using namespace std;

int n;
int m[10001];
int dp[10001];
// dp[n] = dp[n-2] + m[n] -> n-1번째 안마신 경우
// dp[n] = dp[n-3] + m[n-1] + m[n] -> n-1번째 마신 경우

int solv();


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
	}
	cout << solv();

	return 0;
}

int solv() {
	dp[0] = 0;
	dp[1] = m[1];
	dp[2] = dp[1] + m[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + m[i], dp[i - 3] + m[i - 1] + m[i]);
		dp[i] = max(dp[i], dp[i - 1]); // 연속으로 안마신 경우 방지.
	}

	return dp[n];
}
