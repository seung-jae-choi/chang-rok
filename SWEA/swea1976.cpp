#include<iostream>
using namespace std;

int t;
int h1, h2;
int m1, m2;
int h3, m3;
int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> h1 >> m1 >> h2 >> m2;
		if (m1 + m2 > 60) {
			m3 = m1 + m2 - 60;
			h3 = 1;
		}
		else {
			m3 = m1 + m2;
			h3 = 0;
		}
		if (h1 + h2 > 12) {
			h3 += h1 + h2 - 12;
		}
		else {
			h3 += h1 + h2;
		}
		cout << "#" << i << " " << h3 << " " << m3 << "\n";
	}
	return 0;
}
