#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
vector<long long> vll;
long long sum(0),ans(0);

int main()
{
	cin >> n >> k;
	vll.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vll[i];
	sort(vll.begin(), vll.end());
	for (int i = n - 1; i >= 0; i--) {
		if (i < k) ans += sum;
		sum += vll[i];
	}
	cout << ans;

	return 0;
}
