#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t;
int n;
vector<int> vi;
int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		int num;
		for (int j = 0; j < n; j++) {
			cin >> num;
			vi.push_back(num);
		}
		sort(vi.begin(), vi.end());
		cout << "#" << i << " ";
		for (int j = 0; j < n; j++) {
			cout << vi[j] << " ";
		}
		cout << "\n";
		vi.clear();
	}
	return 0;
}
