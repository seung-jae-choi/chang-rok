#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
// 방문 했던 곳 다시 들어가면 "-1" 출력.
// 동,서,남,북 4 방향으로 이동.
//


int N, M;
string s[50];
bool visited[50][50] = { false, };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int dp[50][50] = { 0, };

void Input() {
	cin >> N >> M;
	for(int i=0;i<N;i++)
			cin >> s[i];
}
int go(int y, int x) {
	if (y >= N || y < 0 || x >= M || x < 0 || s[y][x] == 'H') return 0;
	if (visited[y][x]) {
		cout << "-1" << "\n";
		exit(0);
	}
	if (dp[y][x]) return dp[y][x];
	int jump = (int)s[y][x] - (int)'0';
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + jump * dx[i];
		int ty = y + jump * dy[i];
		dp[y][x] = max(dp[y][x], go(ty, tx) + 1);
	}
	visited[y][x] = false;
	return dp[y][x];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	cout << go(0, 0) << "\n";
	return 0;
}
