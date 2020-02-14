#include<iostream>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
#define INF 987654321

int n, m;
int map[101][101];
int result[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
// 방문했는지는 검사 x
queue< pair<int,int> > path;

void bfs(int y, int x) {
	path.push({ y,x });
	result[y][x] = 0;
	while (!path.empty()) {
		int r = path.front().first;
		int c = path.front().second;
		path.pop();
		for (int i = 0; i < 4; i++) {
			int ny = r + dy[i];
			int nx = c + dx[i];
			if (ny< 0|| ny>=n || nx<0 || nx>=m) continue;
			if (map[ny][nx] == 1) {
				if (result[ny][nx] > result[r][c] + 1) {
					result[ny][nx] = result[r][c] + 1;
					path.push({ ny,nx });
				}
			}
			else {
				if (result[ny][nx] > result[r][c]) {
					result[ny][nx] = result[r][c];
					path.push({ ny,nx });
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			map[i][j]=s[j]-'0';
			result[i][j] = INF;
		}
	}
	
	bfs(0,0);
	cout << result[n-1][m-1] << "\n";
	return 0;
}
