// 끝에서부터 task 걸리는거 계산하면 x 최대값 구할 수 있다.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int test,t,n,d;
vector< pair<int, int> > vii;

bool cmp(pair<int, int> v1, pair<int, int> v2) {
	if (v1.second > v2.second) return true;
	else if (v1.second == v2.second) return v1.first > v2.first;
	else return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> test;
	for (int i = 1; i <= test; i++) {
		cin >> n;
		vii.resize(n);
		for (int j = 0; j < n; j++) {
			cin >> vii[j].first >> vii[j].second;
		}
		sort(vii.begin(), vii.end(), cmp);
		for (int j = 0; j < n-1; j++) {
			if (vii[j].second - vii[j].first + 1 > vii[j + 1].second)
				continue;
			else {
				vii[j + 1].second = vii[j].second - vii[j].first;
			}
		}
		int ans = vii[n - 1].second - vii[n - 1].first;
		cout << "#" << i << " " << ans << "\n";
		vii.clear();
	}
	return 0;
}
