#include<iostream>
#include<vector>
using namespace std;

int t, n;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		int ans;
		cin >> ans;
		for (int i = 1; i < n; i++) {
			int num;
			cin >> num;
			if (num*ans > num + ans)
				ans = num * ans;
			else
				ans = ans + num;
		}
		cout << "#" << i << " " << ans << "\n";
	}

	return 0;

}
