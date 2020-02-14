#include<iostream>
#include<vector>
using namespace std;

int N;
vector< vector<int> > d;
vector<char> animal;
vector<long long> number;
void input();
long long rescue(int path);
int main()
{
	cin >> N;
	d.resize(N + 1);
	animal.resize(N + 1);
	number.resize(N + 1);
	input();
	cout << rescue(1);
	return 0;
}

void input() {
	for (int i = 2; i <= N; i++) {
		int end;
		cin >> animal[i] >> number[i] >> end;
		d[end].push_back(i);
	}
}
long long rescue(int path) {
	long long sum(0);
	for (int next : d[path]) {
		sum += rescue(next);
	}
	if (animal[path] == 'S') return number[path] + sum;
	else
		return (sum - number[path] >= 0) ? sum - number[path] : 0;
}
