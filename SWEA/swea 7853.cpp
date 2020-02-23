// 각 자리 수 곱해가면서 1000000007로 나누어야 문제 조건 만족임.(주의)
// 다 곱하고 1000000007로 나누는 것과는 다름(틀린것.)

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int t;
string s;

int main()
{
	long long ans = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> s;
		int size = s.size();
		vector<int> cnt(size);
		if (s[0] != s[1]) cnt[0]=2;
		else cnt[0] = 1;

		for (int j = 1; j < size-1; j++) {
			if (s[j - 1] != s[j] && s[j] != s[j + 1] && s[j - 1] != s[j + 1])
				cnt[j]=3;
			else if (s[j - 1] == s[j] && s[j] == s[j + 1])
				cnt[j]=1;
			else cnt[j]=2;
		}

		if (s[size - 1] != s[size - 2])cnt[size-1]=2;
		else cnt[size - 1] = 1;

		for (int j = 0; j < size; j++) {
			ans = (ans*cnt[j]) % 1000000007;
		}
		cout << "#" << i << " " << ans << "\n";
		ans = 1;
	}
	return 0;
}
