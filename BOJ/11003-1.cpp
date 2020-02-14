//deque 

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int N, L;
vector<int> A;
deque< pair<int, int> > dq; // value,idx

void Input() {
	cin >> N >> L;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		A.push_back(num);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	Input();
	
	for (int i = 0; i < N; i++) {
		if (!dq.empty() && dq.front().second <= i - L)
			dq.pop_front();
		while (!dq.empty() && dq.back().first > A[i])
			dq.pop_back();
		dq.push_back(make_pair(A[i], i));
		cout << dq.front().first << " ";
	}
	cout << "\n";
	return 0;
}
