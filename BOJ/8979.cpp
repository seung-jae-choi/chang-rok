#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Country {
	int num;
	int gold;
	int silver;
	int bronze;
};

int N, K;

bool cmp(Country c1,Country c2) {
	if (c1.gold == c2.gold) {
		if (c1.silver == c2.silver) {
			if (c1.bronze == c2.bronze) return c1.num == K;
			else return c1.bronze > c2.bronze;
		}
		else return c1.silver > c2.silver;
	}
	else {
		return c1.gold > c2.gold;
	}
}

int main()
{
	vector<Country> vc;
	cin >> N >> K;
	vc.resize(N*N);
	for(int i=1;i<=N;i++){
		cin >> vc[i].num >> vc[i].gold >> vc[i].silver
				>> vc[i].bronze;
	}
	sort(vc.begin() + 1, vc.end(), cmp);
	for (int i = 1; i <= N; i++) {
		if (vc[i].num == K) cout << i;
	}
	return 0;
}
