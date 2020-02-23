#include<iostream>
#include<vector>
using namespace std;

int t,n,d;
vector<int> vi;

int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		vi.resize(n);
		for (int j = 0; j < n; j++) {
			cin >> vi[j];
		}
		int idx = 0;
		int ans(0), cnt(0);
		while (idx < n) {
			if (vi[idx] == 1) {
				cnt = 0;
				idx++;
			}
			else {
				if (cnt == d - 1) {
					ans++;
					cnt = 0;
				}
				else cnt++;
				idx++;
			}
		}
		cout << "#" << i << " " << ans << "\n";
		vi.clear();
	}
	return 0;
}
