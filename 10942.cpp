#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> vi;
vector< pair<int, int> > question;
bool dp[2001][2001];

void makedp() {
	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= N-i; j++) {
			if (vi[j] == vi[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = dp[j + i][j] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vi.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> vi[i];
	}
	cin >> M;
	question.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> question[i].first >> question[i].second;
	}
	//초기화
	for (int i = 1; i <= N; i++) {
		dp[i][i] = true;
	}
	for (int i = 1; i < N; i++) {
		if (vi[i] == vi[i + 1])
			dp[i][i + 1] = dp[i + 1][i] = true;
	}
	makedp();
	for (int i = 0; i < M; i++) {
		int start = question[i].first;
		int end = question[i].second;
		if (dp[start][end]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}
