#include<iostream>
using namespace std;

int n;
long long d[91];
pair<long long ,long long> cnt[91];

//d[n]=cnt[n-1].first + 2; n-1 자리가 0
//d[n]=cnt[n-1].second + 1; n-1 자리가 1

int main()
{
	cin >> n;
	d[0] = 0; d[1] = 1; d[2] = 1;
	cnt[0] = { 0,0 }; cnt[1] = { 0,1 };
	cnt[2] = { 1,0 };
	for (int i = 3; i <= n; i++) {
		d[i] = (cnt[i - 1].first) * 2 + (cnt[i - 1].second) * 1;
		cnt[i] = make_pair(cnt[i - 1].first+cnt[i-1].second, cnt[i - 1].first);
	}
	cout << d[n];
	return 0;
}
