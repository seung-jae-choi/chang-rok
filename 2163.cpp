#include<iostream>
using namespace std;

int N, M;

void Input() {
	cin >> N >> M;
}
int cut() {
	return N * M - 1;
}
int main()
{
	Input();
	cout << cut();
	return 0;
}
