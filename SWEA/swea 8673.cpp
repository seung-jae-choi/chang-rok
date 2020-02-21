#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

int t,k;
int n;
queue<int> q;

int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> k;
		n = pow(2, k);
		int num;
		for (int j = 0; j < n; j++) {
			cin >> num;
			q.push(num);
		}
		int sum(0);
		while (!q.empty()) {
			if (q.size() == 1) break;
			int first = q.front();
			q.pop();
			int second = q.front();
			q.pop();
			if (first >= second) q.push(first);
			else q.push(second);
			sum += abs(first - second);
		}
		cout << "#" << i << " " << sum << "\n";
		// while문에서 1개 추가했으므로 삭제.
		q.pop();
		
	}
	return 0;
}
