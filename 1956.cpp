#include<iostream>
#include<algorithm>
using namespace std;
#define infinite 100000

int edge[401][401];
int map[401][401];
int v, e;

void Initialize() {
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) edge[i][j] = 0;
			else
				edge[i][j] = infinite;
		}
	}
}

int main()
{
	cin >> v >> e;

	Initialize();

	for (int i = 0; i < e; i++) {
		int start, end, length;
		cin >> start >> end >> length;
		edge[start][end] = length;
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			map[i][j] = edge[i][j];
		}
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (map[i][k] + map[k][j] < map[i][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	int Min=infinite;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j)continue;
			if (map[i][j] + map[j][i] < Min)
				Min = map[i][j] + map[j][i];
		}
	}
	if (Min == infinite) cout << -1;
	else cout << Min;
	return 0;
}
