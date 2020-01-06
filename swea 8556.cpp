#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

#define nsize 5
#define wsize 4
vector<char> vc;

int main()
{
	int T;
	string s;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> s;
		int size = s.size();
		int cnt(0),j(0);
		while(j<size) {
			if (s[j] == 'n') {
				j += nsize;
				vc.push_back('n');
				cnt++;
			}
			else
			{
				j += wsize;
				vc.push_back('w');
				cnt++;
			}
		}
		int n(0),up(0);
		while (!vc.empty()) {
			if (vc.back() == 'n') {
				if (up == 0) {
					up = 0;
				}
				else {
					up = 2 * up - 90;
				}
			}
			else {
				up = 2 * up + 90;
			}
			n++;
			vc.pop_back();
		}
		while (true)
		{
			if (up % 2 == 0 && n > 1) {
				up /= 2;
				n--;
			}
			else break;
		}
		if (n > 1) {
			n = pow(2, n - 1);
			cout << "#" << i << " " << up << "/" << n << "\n";
		}
		else
			cout << "#" << i << " " << up << "\n";
		vc.clear();
	}
	return 0;
}
