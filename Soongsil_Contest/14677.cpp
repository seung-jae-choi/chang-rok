#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
string s;
int dp[1501][1501][3];
int a[1501];

int solv(int left, int right, int state) {
	
	if (left > right)return 0;

	int &ret = dp[left][right][state];
	if (ret != -1) return ret;
	ret = 0;
	if (a[left] == state) {
		ret = max(ret, solv(left + 1, right, (state + 1) % 3) + 1);
	}
	if (a[right] == state) {
		ret = max(ret, solv(left, right-1, (state + 1) % 3) + 1);
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cin >> s;
	N *= 3;
	for (int i = 0; i < N; i++) {
		char c = s[i];
		switch (c)
		{
		case 'B':
			a[i] = 0;
			break;
		case 'L':
			a[i] = 1;
			break;
		case 'D':
			a[i] = 2;
			break;
		}
	}
	cout << solv(0, N - 1, 0);


	return 0;
}
