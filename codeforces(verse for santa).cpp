#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t, n, s;
	vector<int> vi;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> s;
		vi.resize(n+1);
		int num;
		long long sum(0);
		for (int j = 1; j <= n; j++) {
			cin >> num;
			vi[j] = num;
			sum += num;
		}
		if (sum <= s) {
			cout << "0" << "\n";
			continue;
		}
		sum = 0;
		int ans(0), p(0);
		for (int j = 1; j <= n; j++) {
			if (vi[j] > vi[p]) p = j;
			sum += vi[j];
			if (sum-vi[p] <= s) ans = p;
		}
		cout << ans << "\n";
	}
	return 0;
}
