#include<iostream>
#include<string>
using namespace std;

int t,n;
string s1,s2;
int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		cin >> s1;
		cin >> s2;
		int cnt(0);
		for (int j = 0; j < n; j++) {
			if (s1[j] == s2[j]) cnt++;
		}
		cout << "#" << i << " " << cnt << "\n";
	}
	return 0;
}
