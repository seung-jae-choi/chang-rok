#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
#include<algorithm>
using namespace std;
#define INF 987654321


int t, n, k;
vector< pair<int,int> > vii;
int d[501][501];
int result;

int calculate(int x, int y) {
	return (abs(vii[x].first - vii[y].first)
		+ abs(vii[x].second - vii[y].second));
}

int solv(int now,int cnt) {
	if (now == n - 1) return 0;// 탈출조건
	int &result = d[now][cnt];
	if (result != -1) return result;
	result = INF;
	for (int i = 0; i <= cnt; i++) {
		int next = now + 1 + i;
		if (next > n - 1)continue;
		result = min(result, calculate(now, next) + solv(next, cnt - i));

	}
	return result;
}

int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		vii.resize(n);
		for (int j = 0; j < n; j++) {
			cin >> vii[j].first >> vii[j].second;
		}
		memset(d, -1, sizeof(d));
		cout<<"#"<<i<<" "<<solv(0, k)<<"\n";

		vii.clear();
	}

	return 0;
}
