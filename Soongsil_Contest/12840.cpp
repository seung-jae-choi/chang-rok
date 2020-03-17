#include<iostream>

using namespace std;

#define day 86400

int h, m, s;
int tc;
int t, c;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> m >> s >> tc;
	
	int sum = s + m * 60 + h * 60 * 60;
	for (int i = 0; i < tc; i++) {
		cin >> t;
		if (t == 3) {
			cout << sum / 3600 << " " << (sum / 60) % 60 << " " << sum % 60 << "\n";
		}
		else if (t == 1) {
			cin >> c;
			sum = (sum + c) % day;
		}
		else {
			cin >> c;
			sum=(sum - c) % day;
			while (sum < 0) {
				sum += day;
			}
		}
	}
	return 0;
}
