#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, N, K;
vector< pair<int,float> > score;

bool cmp(pair<int, float>  s1, pair<int, float>  s2) {
	if (s1.second > s2.second)
		return true;
	else
		return false;
}

int search() {
	for (int i = 0; i < N; i++) {
		if (score[i].first == K-1)
			return i;
	}
}

void print(int n, int cutline,int idx) {
	int m = n / cutline;
	if (m == 0)
		cout << "#" << idx << " " << "A+" << "\n";
	else if(m==1)
		cout << "#" << idx << " " << "A0" << "\n";
	else if(m == 2)
		cout << "#" << idx << " " << "A-" << "\n";
	else if(m == 3)
		cout << "#" << idx << " " << "B+" << "\n";
	else if(m == 4)
		cout << "#" << idx << " " << "B0" << "\n";
	else if(m == 5)
		cout << "#" << idx << " " << "B-" << "\n";
	else if(m == 6)
		cout << "#" << idx << " " << "C+" << "\n";
	else if(m == 7)
		cout << "#" << idx << " " << "C0" << "\n";
	else if(m == 8)
		cout << "#" << idx << " " << "C-" << "\n";
	else
		cout << "#" << idx << " " << "D0" << "\n";
}

int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> N >> K;
		int x,y,z;
		double sum;
		for (int j = 0; j < N; j++) {
			cin >> x >> y >> z;
			sum = x * (0.35) + y * (0.45) + z * (0.2);
			score.push_back({ j,sum });
		}
		sort(score.begin(), score.end(),cmp);
		int n = search();
		int cutline = N / 10;
		print(n, cutline,i);
		score.clear();
	}
	return 0;
}

 
