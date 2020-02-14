#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int T, N, K,num,min_m;

struct Node {
	vector<int> vi;
	bool visit;
	int money;
	Node() {
		visit = false;
		money = -1;
	}
};

class graph {
public:
	void insetEdge(int x, int y) {
		n[x].vi.push_back(y);
	}
	void reset() {
		for (int i = 1; i <= N; i++) {
			n[i].visit = false;
			n[i].money = -1;
		}
	}
	void bfs(int root) {
		queue<int> q;
		int cnt = N;
		int m = 0;
		q.push(root);
		n[root].visit = true;
		n[root].money = 1;
		
		while (!q.empty())
		{
			Node *t = &n[q.front()];
			m += t->money;
			for (int i = 0; i < t->vi.size(); i++) {
				if (n[t->vi[i]].visit == false) {
					q.push(t->vi[i]);
					n[t->vi[i]].visit = true;
					n[t->vi[i]].money = n[q.front()].money + 1;
				}
			}
			q.pop();
			cnt--;
		}
		if (cnt == 0) {
			min_m = min(m, min_m);
		}
	}

private:
	Node n[5001];
};

int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		graph g;
		min_m = 50000001;
		for (int j = 1; j <= N; j++) {
			cin >> K;
			for (int x = 0; x < K; x++) {
				cin >> num;
				g.insetEdge(num, j);
			}
		}
		for (int j = 1; j <= N; j++) {
			g.bfs(j);
			g.reset();
		}
		cout << "#" << i << " " << min_m << "\n";
	}
	return 0;
}
