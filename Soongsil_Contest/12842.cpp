#include<iostream>

using namespace std;

int n,s,m;
int pv[100005];
int x;
int main()
{
	cin >> n >> s;
	cin >> m;
	
	for (int i = 1; i <= m; i++) {
		cin >> pv[i];
	}
	int sum = 0;
	for (int t = 0; t < 100000; t++) {
		for (int i = 1; i <= m; i++) {
			if (t % pv[i] == 0) {
				sum++;
				if (sum >= n - s) {
					cout << i;
					exit(0);
				}
			}
		}
	}

	return 0;
}
