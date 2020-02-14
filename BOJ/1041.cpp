#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long  N;
long long n1, n2, n3;
int m1, m2, m3;
vector<int> vi(6);

int main()
{
	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> vi[i];
	}
	long long sum(0);
	if (N == 1) {
		sort(vi.begin(), vi.end());
		for (int i = 0; i < 5; i++) {
			sum += vi[i];
		}
	}
	else {
		vi[0] = min(vi[0], vi[5]);
		vi[1] = min(vi[1], vi[4]);
		vi[2] = min(vi[2], vi[3]);
		sort(vi.begin(), vi.begin() + 3);
		m3 = vi[0] + vi[1] + vi[2];
		m2 = vi[0] + vi[1];
		m1 = vi[0];

		n1 = 4 * (N - 2)*(N - 1) + (N - 2)*(N - 2);
		n2 = 4 * (N - 1) + 4 * (N - 2);
		n3 = 4;
		sum += n1 * m1;
		sum += n2 * m2;
		sum += n3 * m3;
	}
	cout << sum << "\n";
	return 0;
}
