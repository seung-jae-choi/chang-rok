#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
int divide(int x,int y);
int N;
int result;
int ans(0);
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				result = divide(1, i) + divide(i+1, j) 
					+ divide(j+1, k)+ divide(k+1,N);
				if (ans < result) {
					ans = result;
				}
			}
		}
	}

	cout << ans;
	
	return 0;
}

int divide(int x,int y) {
	int mul = 1;
	for (int i = x-1; i < y; i++) {
		mul *= a[i];
	}
	return mul;
}
