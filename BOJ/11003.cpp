// 시간 초과

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, L;
vector<int> A;

void Input() {
	cin >> N >> L;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		A.push_back(num);
	}
}
int find_min(int start, int end) {
	int minimum(1000000000);
	if (start == end) return A[0];
	for (int i = start; i < end; i++) {
		if(minimum > min(A[i],A[i+1]))
			minimum = min(A[i], A[i + 1]);
	}
	return minimum;
}

void slide(int idx) {
	if (idx - L + 2 <= 1)
		cout << find_min(0, idx) << " ";
	else
	{
		cout << find_min(idx - L + 1, idx) << " ";
	}

}

int main()
{
	Input();
	for (int i = 0; i < 12; i++)
		slide(i);
	return 0;
}
