#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int tc;
int n, m;
vector<int> w;
int total;
int now;


int main()
{
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			int weight;
			cin >> weight;
			w.push_back(weight);
		}
		int maximum(0);
		for (int j = 0; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				now = w[j] + w[k];
				if (now > m) continue;
				maximum = max(now, maximum);
			}
			if (maximum == m) break;
		}
		if(maximum != 0)
			cout << "#" << i << " " << maximum << "\n";
		else
			cout << "#" << i << " " << -1 << "\n";
		w.clear();
	}
	return 0;
}
