#include<iostream>
using namespace std;

int ex[13];
int temp[13];
int n;

void recursive(int start,int m);

int main()
{	
	
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			cin >> ex[i];
		}
		recursive(0, 0);
		cout << "\n";
	}
	
	return 0;
}

void recursive(int start,int m) {
	if (m == 6) {
		for (int i = 0; i < 6; i++) {
			cout << temp[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = start; i < n; i++) {
		temp[m] = ex[i];
		recursive(i + 1, m + 1);
	}
}
