#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

int n, m, k;

bool map[1001][1001];

bool flag[4];
// 0 :i+j는 홀수 i는 홀수
// 1 :i+j는 홀수 i는 짝수
// 2 :i+j는 짝수 i는 홀수
// 3 :i+j는 짝수 i는 짝수

void check(int x, int y) {
	if ((x + y) % 2 == 0) { // x+y는 짝수
		if (x % 2 == 0) // x는 짝수
			flag[3] = true;
		else //x는 홀수
			flag[2] = true;
	}
	else { //x+y는 홀수
		if (x % 2 == 0) // x는 짝수
			flag[1] = true;
		else // x는 홀수
			flag[0] = true;
	}
}

int main()
{
	
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		check(x, y);
	}
	for (int i = 0; i < 4; i++) {
		if (flag[i] == false) {
			cout << "NO";
			exit(0);
		}
	}
	cout << "YES";
	return 0;
}
