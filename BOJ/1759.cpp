#include<iostream>
using namespace std;
#include<algorithm>


int L, C,m,start;
int mo(0), ja(0);

char v[15];
char w[15];
void cal(int start,int m);
int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> v[i];
	}
	sort(v,v+C);
	cal(0, 0);

	return 0;
}

void cal(int start,int m) {
	if (m == L) {
		if (mo >= 1 && ja >= 2) {
			for (int i = 0; i < L; i++)
				cout << w[i];
			cout << '\n';
		}
		return;
	} 
	for (int i = start; i < C; i++) {
		w[m]=v[i];
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			mo++;
			cal(i + 1, m + 1);
			mo--;
		}
		else {
			ja++;
			cal(i + 1, m + 1);
			ja--;
		}	
	}
}
