//둘 다 최선의 방법으로 게임을 진행하므로
//두 개의 돌 중 하나는 0이 나올 때가 있다.
//KJ가 먼저 시작하므로
//이 때, 다른 한 쪽의 돌이 1이하이면 DH의 승.


#include<iostream>
#include<string>
using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string ans;
	long long r, b;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> r >> b;

		r = r - b;
		if (r < 0) {
			r = (-1)*r;
		}
		if (r < 2) {
			ans = "DH";
		}
		else {
			ans = "KJ";
		}
		cout << "#" << i << " " << ans << "\n";
	}
	return 0;
}
