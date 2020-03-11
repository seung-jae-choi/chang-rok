#include <iostream>
using namespace std;
#define mod 10007

long long dp[1001];
int n;

int main() {
	cin>>n;
	dp[1]=1; dp[2]=3;
	for(int i=3;i<=n;i++){
		dp[i]=(dp[i-1]+dp[i-2]*2)%mod;
	}
	cout << dp[n]%mod;
	return 0;
}
