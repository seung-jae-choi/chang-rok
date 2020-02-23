//cin 도중에 계산 하지 말자.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t,n,m;
long long c1, c2;
long long minV;
int nC, nH,cnt;
vector<long long> cow;
vector<long long> h;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		cin >> c1 >> c2;
		cow.resize(n);
		h.resize(m);
		minV = 1e9;
		for (int j = 0; j < n; j++) {
			cin >> cow[j];
		}
		long long num,min(200000000);
		for (int j = 0; j < m; j++) {
			cin >> h[j];
		}
		sort(cow.begin(), cow.end());
		sort(h.begin(), h.end());
		nC = 0; nH = 0; cnt = 0;
		while (nC < n&&nH < m) {
			int tmp = abs(cow[nC] - h[nH]);
			if (tmp == minV) {
				cnt += 1;
			}
			else if (tmp < minV) {
				minV = tmp;
				cnt = 1;
			}
			if (cow[nC] > h[nH])nH++;
			else nC++;
		}
		int min_d = abs(c1 - c2) + minV;
		cout << "#" << i << " " << min_d<< " " << cnt << "\n";
		cow.clear();
		h.clear();
	}
	return 0;
}
