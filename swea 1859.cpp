//백만장자프로젝트
#include<iostream>
using namespace std;

int T, N;
int num[1000002] = { 0, };

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		long long ans(0);
		for (int j = 0; j < N; j++) {
			cin >> num[j];
		}
		int max = num[N - 1];
		for (int j = N - 1; j >= 0; j--) {
			if (max >= num[j]) {
				ans += max - num[j];
			}
			else {
				max = num[j];
			}
		}
		cout << "#" << i + 1 << " " << ans << "\n";
		for (int j = 0; j < N; j++) {
			num[j] = 0;
		}
	}
	return 0;
}
