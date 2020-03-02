#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int t;
int n, x, m;
int l, r, s;
int mmax;
vector< pair<int, int> > vii; //l번부터r번 까지
int hamster[11];
int cage[7];
int ans[7];
bool flag;

bool check() {
	for (int i = 0; i < m; i++) {
		int l = vii[i].first;
		int r = vii[i].second;
		int cnt(0);
		for (int j = l; j <= r; j++) {
			cnt += cage[j];
		}
		if (cnt != hamster[i]) return false;
	}
	return true;
}

void dfs(int a, int tot) {
	if (a == n) { //탈출조건
		if (check()) {
			if (tot > mmax) {
				mmax = tot;
				flag = true;
				for (int i = 1; i <= n; i++) {
					ans[i] = cage[i];
				}
			}
			return;
		}
		else return;
	}
	for (int i = 0; i <= x; i++) {
		cage[a + 1] = i;
		dfs(a + 1, tot + i);
	}
}

int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> x >> m;
		vii.resize(m);
		mmax = -1;
		flag = false;
		memset(hamster, 0, sizeof(hamster));
		memset(cage, 0, sizeof(cage));
		memset(ans, 0, sizeof(ans));
		for (int j = 0; j < m; j++) {
			cin >> vii[j].first >> vii[j].second >> hamster[j];
		}
		dfs(0, 0);
		cout << "#" << i << " ";
		if (flag) {
			for (int j = 1; j <= n; j++) {
				cout << ans[j] << " ";
			}
		}
		else {
			cout << "-1";
		}
		cout << "\n";
		vii.clear();
	}
	return 0;
}
