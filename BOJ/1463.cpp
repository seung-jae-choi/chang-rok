#include<iostream>
using namespace std;

// d[n] = d[n/3] + 1;
// d[n] = d[n/2] + 1;
// d[n] = d[n-1] + 1;

int n;
int d[1000001];
int solve(int target);
int min(int x, int y);

int main()
{
	cin >> n;
	cout << solve(n);
	

	return 0;
}

int solve(int target) {
	d[1] = 0;
	for (int i = 2; i <= target; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) {
			d[i] = min(d[i], d[i / 2] + 1);
		}
		if (i % 3 == 0) {
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}

	return d[target];
}

int min(int x, int y) {
	if (x > y)return y;
	else
		return x;

}
