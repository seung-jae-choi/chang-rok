#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, int> pii;
int n, m, k, t;
int map[301][301];
int check[301][301][2];
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

vector<pii> clean;

int main()
{
	cin >> n >> m >> k >> t;

	queue<pii> gom;
	clean.resize(k);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		check[x][y][0] = 1;
		gom.push({ x,y });
	}
	for (int i = 0; i < k; i++) {
		cin >> clean[i].first >> clean[i].second;
	}
	int cnt = 0;
	while (t--) {
		int size = gom.size();
		while (size--) {
			int x = gom.front().first;
			int y = gom.front().second;
			gom.pop();
			check[x][y][cnt] = false;
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
					if (!check[nx][ny][(cnt + 1) % 2]) {
						check[nx][ny][(cnt + 1) % 2] = true;
						gom.push({ nx,ny });
					}
				}
			}
		}
		cnt++;
	}
	for (int i = 0; i < k; i++) {
		int x = clean[i].first;
		int y = clean[i].second;
		if (check[x][y][cnt % 2]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
