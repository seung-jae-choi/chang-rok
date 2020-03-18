#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

int n, t;
deque<int> di;
bool flag;
int main()
{
	cin >> n;
	vector<int> money(n);
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}
	int mmax(-1),sum,mmin;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			sum = 0; mmin = money[j]; flag = true;
			for (int k = j; k < j + i; k++) {
				if (j + i > n) {
					flag = false;
					break;
				}
				if (mmin > money[k]) mmin = money[k];
			}
			if(flag)
				sum = i * mmin;
			if (mmax < sum) mmax = sum;
		}
	}
	cout << mmax;
	return 0;
}
