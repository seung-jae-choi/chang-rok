//시간초과
#include<iostream>
#include<vector>
using namespace std;

int t,n;
vector< pair<int, int> > vii;

int main()
{
	vii.push_back({ 0,0 });
	vii.push_back({ 1,1 });
	
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		if (n == 1) {
			cout << "#" << i << " " << vii[1].first <<" "
				<< vii[1].second << "\n";
			continue;
		}
		int size = vii.size();
		for (int j = size; j <= n; j++) {
			int num_f = vii[j-1].second + 2;
			int cnt = 2 * j - 1;
			int num_e = num_f + 2 * (cnt - 1);
			vii.push_back({ num_f,num_e });
			num_f = num_e + 2;
		}
		cout << "#" << i << " " << vii[n].first << " "
			<< vii[n].second << "\n";
	}
	return 0;
}
