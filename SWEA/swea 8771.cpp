#include<iostream>
using namespace std;


int t;
long long n, a, b;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> a >> b;
		if (n == 1) {
			if (a == b) {
				cout << "#" << i << " " << 1 << "\n";
			}
			else
			{
				cout << "#" << i << " " << 0 << "\n";
			}
		}
		else if (a > b) {
			cout << "#" << i << " " << 0 << "\n";
		}
		else {
			cout << "#" << i << " " << (b*(n - 1) + a) -(a * (n - 1) + b) +1 << "\n";
		}
	}
	return 0;
}
