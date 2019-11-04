#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// greedy algorithm

class Time {
public:
	int begin;
	int end;
};
bool cmp(Time a,Time b);
int solv(vector<Time> t);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Time> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i].begin >> t[i].end;
	}
	sort(t.begin(), t.end(), cmp);
	
	cout << solv(t);

	return 0;
}
bool cmp(Time a,Time b) {
	if (a.end == b.end)
		return a.begin < b.begin;
	else
		return a.end < b.end;
}
int solv(vector<Time> t) {
	int cnt(0);
	int m(0);
	for (int i = 0; i < t.size(); i++) {
		if (m <= t[i].begin) {
			m = t[i].end;
			cnt++;
		}
	}
	return cnt;
}
