#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define max_val 2147483647

int N;
int S[21][21];
vector<int> start;
vector<int> link;
int result(max_val);

void Input() {
	cin >> N;
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
}
void calculate() {
	int start_sum(0), link_sum(0);
	for(int i=0;i<N/2;i++)
		for (int j = i + 1; j < N / 2; j++) {
			if (i == j) continue;
			start_sum += S[start[i]][start[j]] + S[start[j]][start[i]];
			link_sum += S[link[i]][link[j]] + S[link[j]][link[i]];
		}
	result = min(result, abs(start_sum - link_sum));
}
void solv(int idx) {
	if (idx == N+1) {
		if (start.size() == N / 2 && link.size() == N / 2) {
			calculate();
		}
		return;
	}
	start.push_back(idx);
	solv(idx + 1);
	start.pop_back();

	link.push_back(idx);
	solv(idx + 1);
	link.pop_back();
}
int main() {
	Input();
	solv(1);
	cout << result;
	return 0;
}
