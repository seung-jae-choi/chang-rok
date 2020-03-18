#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,L;
int gold;

int main()
{
	cin >> N;
	vector<int> card(N);
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end(),greater<int>());

	for (int i = 1; i < N; i++) {
		gold = gold + card[0] + card[i];
	}
	cout << gold;

	return 0;
}
