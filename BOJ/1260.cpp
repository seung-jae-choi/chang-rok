#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

queue<int> b;
stack<int> d;
bool flag[10001];
bool map[1001][1001];
int n, m, v;

void bfs() {
	memset(flag, 0, sizeof(flag));
	b.push(v);
	while (!b.empty()) {
		int x = b.front();
		b.pop();
		if (flag[x] == false)
			cout << x << " ";
		if (flag[x] == false) {
			flag[x] = true;
			for (int i = 1; i <= n; i++) {
				if (map[x][i] == true) b.push(i);
			} 
		}
	}
}

void dfs() {
	memset(flag, 0, sizeof(flag));
	d.push(v);
	while (!d.empty()) {
		int x = d.top();
		if(flag[x]==false)
			cout << x << " ";
		d.pop();
		if (flag[x] == false) {
			flag[x] = true;
			for (int i = n; i >= 1; i--) {
				if (map[x][i] == true ) d.push(i);
			}
		}
	}
	cout << "\n";
}

int main()
{
	cin >> n >> m >> v;
	int start, end;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		map[start][end] = true;
		map[end][start] = true;
	}
	dfs();
	bfs();

	return 0;
}
