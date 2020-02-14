#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> a;
int sol(void);
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	
	cout << sol();
	
	return 0;
}

int sol(void) {
	sort(a.begin(), a.end());
	int result = a[0] * a[n - 1];
	return result;
}
