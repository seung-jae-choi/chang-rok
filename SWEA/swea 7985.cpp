#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int t,k,n,mid;
vector<int> vi;


int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> k;
		n = pow(2, k) - 1;
		int num;
		for (int j = 0; j < n; j++) {
			cin >> num;
			vi.push_back(num);
		}
		mid = n / 2;
		int tmp;
		cout << "#" << i << " ";
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < pow(2, i); j++) {
				if (mid == 0) {
					cout << vi[mid + 2 * j]<<" ";
				}
				else {
					tmp = pow(2, k - i);
					cout << vi[mid + tmp * j] <<" ";
				}
			}
			mid /= 2;
			cout << "\n";
		}
		vi.clear();
	}
	return 0;
}
