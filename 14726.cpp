#include<iostream>
#include<string>
using namespace std;

int T;
string s[1000];
void Input() {
	cin >> T;
	for (int i = 0; i < T; i++)
		cin >> s[i];
}

void decision(int idx) {
	int sum(0);
	for (int j = 15; j >= 0; j--) {
		int stoint = (int)s[idx][j] - (int)'0';
		if (j % 2 == 0) {
			if (stoint * 2 >= 10) {
				stoint *= 2;
				sum = sum + (stoint / 10) + (stoint % 10);
			}
			else
			{
				sum = sum + stoint * 2;
			}
		}
		else
			sum += stoint;
	}
	if (sum % 10 == 0)
		cout << "T" << "\n";
	else
		cout << "F" << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	for (int i = 0; i < T; i++) {
		decision(i);
	}
	
	return 0;
}
