#include<iostream>
using namespace std;

int a[100001];
int b[100001];
int cross[100001];
int n,flag(0);

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cross[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> b[i];
	}
	long long sum = 0;
	long long min = cross[1];
	for (int i = 1; i < n; i++) {
		int tmp = a[i] - b[i];
		sum += tmp;
		if (sum + cross[i+1] < min) {
			min = sum + cross[i + 1];
			flag = i + 1;
		}
	}
	sum = cross[flag];
	for (int i = 1; i < n; i++) {
		if (i < flag) sum += a[i];
		else sum += b[i];
	}
	cout << flag << " " << sum;
	return 0;
}
