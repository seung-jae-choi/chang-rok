#include<iostream>
#include<cstring>
using namespace std;

int t,n,k;
int map[15][15];

int check_c(int y) {
	int answer(0);
	int cnt(0);
	int idx(0);
	while (true)
	{
		if (map[y][idx] == 0) {
			if (cnt == k) answer++;
			cnt = 0;
			idx++;
		}
		else {
			cnt++;
			idx++;
		}
		if (idx == n) {
			if (cnt == k) answer++;
			break;
		}
	}
	return answer;
}

int check_r(int x) {
	int answer(0);
	int cnt(0);
	int idx(0);
	while (true)
	{
		if (map[idx][x] == 0) {
			if (cnt == k) answer++;
			cnt = 0;
			idx++;
		}
		else {
			cnt++;
			idx++;
		}
		if (idx == n) {
			if (cnt == k) answer++;
			break;
		}
	}
	return answer;
}

int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		memset(map, 0, sizeof(map));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> map[j][k];
			}
		}
		int sum1(0),sum2(0);
		//가로 검사
		for (int j = 0; j < n; j++) {
			sum1 += check_r(j);
			sum2 += check_c(j);
		}
		cout << "#" << i << " " << sum1 + sum2 << "\n";
	}
	return 0;
}
