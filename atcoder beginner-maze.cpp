// not solved.
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define mp make_pair

int h, w;
char m[21][21];
queue< pair<int, int> > path;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int cache[21][21];

int solv(int idx1,int idx2) {
	int max(0);
	path.push(mp(idx1,idx2));
	cache[idx1][idx2] = 1;
	while (!path.empty())
	{
		int r = path.front().first;
		int c = path.front().second;
		path.pop();
		for (int i = 0; i < 4; i++) {
			int ny = r + dy[i];
			int nx = c + dx[i];
			if (0 <= ny && ny < h && 0 <= nx && nx < w 
				&& cache[ny][nx]==0 && (ny!=idx1||nx!=idx2)) {
				if (m[ny][nx] == '.') {
					path.push(mp(ny,nx));
					cache[ny][nx] = cache[r][c] + 1;
				}
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (cache[i][j] > max)
				max = cache[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		memset(cache[i], 0, w * sizeof(int));
	}
	return max-1;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> h >> w;
	int maximum(0);
	for(int i=0;i<h;i++)
		for (int j = 0; j < w; j++) {
			cin >> m[i][j];
		}
	for (int i = 0; i < h; i++) {
		memset(cache[i], 0, w * sizeof(int));
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (m[i][j] == '.') {
				int tmp = solv(i, j);
				maximum = max(tmp,maximum);
			}
		}
	}
	cout << maximum;
	return 0;
}
