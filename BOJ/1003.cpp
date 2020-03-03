#include<iostream>
#include<cstring>
using namespace std;

int t,N;
pair<int,int> fibo[41];


void fibonacci(int n) {
	if (fibo[n] == make_pair(0, 0)) {
		fibo[n].first = fibo[n - 1].first + fibo[n - 2].first;
		fibo[n].second = fibo[n - 1].second + fibo[n - 2].second;
	}
}

int main()
{
	memset(fibo, 0, sizeof(fibo));
	fibo[0] = { 1,0 };
	fibo[1] = { 0,1 };
	for (int i = 2; i <= 40; i++) {
		fibonacci(i);
	}
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> N;
		cout << fibo[N].first << " " << fibo[N].second << "\n";
	}
	return 0;
}
