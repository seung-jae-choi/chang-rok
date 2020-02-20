#include<iostream>
#include<cstring>
using namespace std;

int t;
int m[9][9];

bool check_r() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = j+1; k < 9; k++) {
				if (m[i][j] == m[i][k]) return false;
			}
		}
	}
	return true;
}

bool check_c() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = j + 1; k < 9; k++) {
				if (m[j][i] == m[k][i]) return false;
			}
		}
	}
	return true;
}

bool check_s() {
	for (int i = 0; i < 3;i++) {
		for (int j = 0; j < 3;j++) {
			int sum(0);
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					sum += m[i * 3 + y][j * 3 + x];
				}
			}
			if (sum != 45) return false;
		}
	}
	return true;
}
int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		memset(m, 0, sizeof(m));
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				cin >> m[j][k];
			}
		}
		//가로검사
		if (!check_r()) {
			cout << "#" << i << " " << 0 << "\n";
			continue;
		}
		//세로검사
		if (!check_c()) {
			cout << "#" << i << " " << 0 << "\n";
			continue;
		}
		//정사각형검사
		if (!check_s()) {
			cout << "#" << i << " " << 0 << "\n";
			continue;
		}
		cout << "#" << i << " " << 1 << "\n";
	}
	return 0;
}
