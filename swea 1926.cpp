#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N;

int count(int num) {
	int cnt(0);
	while (true)
	{
		int digit = num % 10;
		if (digit == 3 || digit == 6 || digit == 9) {
			cnt++;
		}
		num = num / 10;
		if (num == 0) break;
	}
	return cnt;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int cnt = count(i);
		if (cnt == 0)
			cout << i <<" ";
		else {
			for (int j = 0; j < cnt; j++) {
				cout << "-";
			}
			cout << " ";
		}
	}
	return 0;
}
