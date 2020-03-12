#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int n;

int solv(int m) {
	for (int i = 2; i <= sqrt(m); i++) {
		if (m % i == 0) {
			return i;
		}
	}
	return -1;
}

int main()
{
	cin >> n;
	int ans = solv(n);
	if (ans == -1) {
		cout << n-1;
	}
	else {
		cout << n-(n / ans);
	}
	return 0;
}
