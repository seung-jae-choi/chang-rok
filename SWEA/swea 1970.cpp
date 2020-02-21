#include<iostream>
using namespace std;

int t;

int money;
int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> money;
		int a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0);
		while (money >= 50000) {
			money -= 50000;
			a++;
		}
		while (money >= 10000) {
			money -= 10000;
			b++;
		}
		while (money >= 5000) {
			money -= 5000;
			c++;
		}
		while (money >= 1000) {
			money -= 1000;
			d++;
		}
		while (money >= 500) {
			money -= 500;
			e++;
		}
		while (money >= 100) {
			money -= 100;
			f++;
		}
		while (money >= 50) {
			money -= 50;
			g++;
		}
		while (money >= 10) {
			money -= 10;
			h++;
		}
		cout << "#" << i << "\n";
		cout << a << " " << b << " " << c << " " << d
			<< " " << e << " " << f << " " << g << " " << h << "\n";
	}
	return 0;
}
