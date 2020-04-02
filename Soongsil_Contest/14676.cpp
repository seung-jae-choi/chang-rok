//comment
//해당 건물의 하위 건물의 정보를 일일이 검사하는 방식 -> 총 개수를 세서 검사하는 방식.

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N, M, K;
int degree[100001];
int built[100001];
vector< vector<int> > adj;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	adj.resize(N + 1);
	memset(built, 0, sizeof(built));
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		degree[y]++;
	}
	bool flag = true;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 1) {
			if (degree[y] > 0) flag = false;
			if (built[y] == 0) {
				for (auto &next : adj[y]) degree[next]--;
			}
			built[y]++;
		}
		else {
			if (!built[y]) flag = false;
			built[y]--;
			if (built[y] == 0) {
				for (auto &next : adj[y]) degree[next]++;
			}
		}
	}
	if (flag)
		cout << "King-God-Emperor";
	else
		cout << "Lier!";
	return 0;
}
