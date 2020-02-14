#include<iostream>
using namespace std;

int t ;
long long n, f, e;
int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		f = 2 * n*n - 4 * n + 3;
		e = 2 * n*n - 1;
		cout << "#" << i << " " << f << " " << e << "\n";
	}
	return 0;
}
