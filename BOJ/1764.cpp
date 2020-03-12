#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<string> a;
vector<string> b;
vector<string> c;
string str;
int n,m;

int main()
{
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (binary_search(a.begin(), a.end(), str)) {
			c.push_back(str);
		}
	}
	sort(c.begin(), c.end());
	cout << c.size() << "\n";
	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << "\n";
	}
	return 0;
}
