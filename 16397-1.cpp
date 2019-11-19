#include<iostream>
#include<queue>
using namespace std;

int N, T, G;
queue<pair <int, int> > q;
bool visited[100000];

void Input() {
	cin >> N >> T >> G;
	q.push({ N,0 });
	visited[N] = true;
}
int B(int num) {
	num *= 2;
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
	default:
		break;
	}
	return num;
}
void escape() {
	while (!q.empty())
	{
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt > T) {
			cout << "ANG";
			return;
		}
		if (n == G) {
			cout << cnt;
			return;
		}
		if ((n + 1 <= 99999) && !visited[n + 1]) {
			q.push({ n+1 ,cnt + 1 });
			visited[n + 1] = true;
		}
		int n1 = B(n);
		if ((n * 2 <= 99999) && !visited[n1]) {
			q.push({ n1,cnt + 1 });
			visited[n1] = true;
		}
	}
	cout << "ANG";
}

int main() {
	Input();
	escape();
	return 0;
}
