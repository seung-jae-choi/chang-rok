#include<iostream>
#include<algorithm>
using namespace std;

// i 번째 선택시 고려사항
// dp[i] = max( dp[i-1], dp[i-2] + a[i]*i )
// max가 dp[i-1]이면 i 번째에는 i를 안고른것.
// else -> i를 고른경우(i-1를 안고르고, dp[i-2]에다가 i고른거 더함.
typedef long long ll;

int n;
ll a[100001] = { 0, };
ll dp[100001];

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a[num]++;
	}
}
void choice() {
	dp[0] = 0;
	dp[1] = a[1] * 1;
	for (int i = 2; i <= 100000; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + i * a[i]);
	}
}
int main()
{
	Input();
	choice();
	cout << dp[100000];
	return 0;
}
