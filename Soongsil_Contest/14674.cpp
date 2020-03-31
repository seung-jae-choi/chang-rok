#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const double Eps = 0.000000000000001;

int n, k;
int i, c, h;

typedef pair<int, int> pii;

vector< pii > vi;
long double g[1005];



bool cmp(pii p1, pii p2) {
	int money1 = p1.second;
	int money2 = p2.second;
	int num1 = p1.first;
	int num2 = p2.first;
	long double x1 = g[num1]; //가성비
	long double x2 = g[num2];
	

	if (x1 > x2)return true;
	else if (x1 < x2)return false;
	else {
		if (money1 == money2) {
			return num1 < num2;
		}
		else return money1 < money2;
	}
	
}

int main() {
	
	cin >> n >> k;
	vi.resize(n+1);
	
	for (int j = 1; j <= n; j++) {
		cin >> i >> c >> h;	
		g[i] = (long double)h / (long double)c;
		vi[j].first = i;
		vi[j].second = c;
	}
	sort(vi.begin()+1, vi.end(), cmp);
	for (int i = 1; i <= k; i++) {
		cout << vi[i].first << "\n";
	}

	return 0;
}
