#include<iostream>
#include<vector>
using namespace std;

int t;
int num;
vector<int> vi;

int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int min(10000), max(0);
		for (int j = 0; j < 10; j++) {
			cin >> num;
			if (num < min) min = num;
			if (num > max)max = num;
			vi.push_back(num);
		}
		int sum(0);
		for (int j = 0; j < 10; j++) {
			if (vi[j] == min || vi[j]==max ) {
				continue;
			}
			else {
				sum += vi[j];
			}
		}
		int r = sum % 8;
		int r1 = r * 10;
		if (r == 0)
			cout << "#" << i << " " << sum / 8 << "\n";
		else {
			if (r1 / 8 >= 5)
				cout << "#" << i << " " << (sum / 8) + 1 << "\n";
			else
				cout << "#" << i << " " << (sum / 8) << "\n";
		}
		vi.clear();
	}
	return 0;
}
