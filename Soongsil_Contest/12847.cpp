#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

int n, m;

int main()
{
	cin >> n >> m;
	vector<long long> arr(n + 1);
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] = arr[i - 1] + arr[i];
	}
	long long ans(-1),sum;
	for (int i = m; i <= n; i++) {
		sum = arr[i] - arr[i - m];
		if (sum > ans) ans = sum;
	}
	cout << ans;

	return 0;
}
