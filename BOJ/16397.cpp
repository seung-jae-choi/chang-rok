//dfs로 풀었는데 stack overflow error뜸. -> bfs로 풀어야할듯.

#include<iostream>
using namespace std;

int N, T, G;

void Input() {
	cin >> N >> T >> G;
}
int B(int num) {
	num *= 2;
	if (num > 99999) {
		cout << "ANG";
		exit(0);
	}
	int temp = num, cnt(0);
	while (temp != 0) {
		temp = temp / 10;
		cnt++;
	}
	switch (cnt)
	{
	case 1:
		num = num - 1;
		break;
	case 2:
		num = num - 10;
		break;
	case 3:
		num = num - 100;
		break;
	case 4:
		num = num - 1000;
		break;
	case 5:
		num = num - 10000;
		break;
	}
	return num;
}
void escape(int cnt) {
	if (N > 99999) return;
	if (cnt < T) { 
		if (N == G) {
			cout << cnt << "\n";
			exit(0);
		}
	}
	else if (cnt == T) {
		if (N == G) {
			cout << cnt << "\n";
			exit(0);
		}
		else return;
	}
	N += 1;
	escape(cnt + 1);
	N -= 1;
	int temp = N;
	N = B(N);
	escape(cnt + 1);
	N = temp;
	if (cnt == 0) {
		cout << "ANG";
		exit(0);
	}
}
int main()
{
	Input();
	escape(0);
	return 0;
}
