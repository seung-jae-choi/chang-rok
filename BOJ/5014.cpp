#include<iostream>
#include<queue>
using namespace std;

int f, s, g, u, d;
// f:건물총층수,s:강호,g:스타트링크,u:업,d:다운


queue<int> pos;
int visited[1000001];
int main()
{
	cin >> f >> s >> g >> u >> d;
	
	pos.push(s);
	visited[s] = 1;
	while (!pos.empty()) {
		int floor = pos.front();
		pos.pop();
		if (floor == g) {
			cout << visited[floor]-1;
			exit(0);
		}
		
		int x = floor + u;
		if (x <= f && visited[x] == 0) {
			visited[x] = visited[floor] + 1;
			pos.push(x);
		}
		int y = floor - d;
		if (y >= 1 && visited[y] == 0) {
			visited[y] = visited[floor] + 1;
			pos.push(y);
		}
		
	}
	cout << "use the stairs";
	return 0;
}
