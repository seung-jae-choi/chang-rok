#include<iostream>
using namespace std;

// 소시지 n개를 한줄로 만들면 (m-1)번 잘라야한다.
// 소시지 3개, 평론가 4명의 경우 -> 3번(4-1)
// 소시지 2개, 평론가 6명의 경우 -> 4번(6-2)
// 소시지 3개, 평론가 9명의 경우 -> 6번(9-3)
// 최대공약수
int solve(int a, int b);

int main()
{
	int N, M;
	cin >> N >> M;
	cout << M-solve(N, M);
	return 0;
}

int solve(int a, int b) {
	if (a%b == 0)
		return b;
	return solve(b, a%b);
}
