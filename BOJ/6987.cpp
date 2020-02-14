#include <iostream>
using namespace std;

#define WIN 0
#define DRAW 1
#define LOSE 2

bool N[4];
int input[4][6][3];
int temp[6][3];

bool check(int index);
void solve(int team1, int team2);

/*
a : bcdef
b : cdef
c : def
d : ef
e : f
*/

int main() {

	for (int t = 0; t < 4; t++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> input[t][i][j];
			}
		}
	}
	solve(0, 1); // game
	for (int i = 0; i < 4; i++) {
		if (N[i])
			cout << "1 ";
		else
			cout << "0 ";
	}
}

void solve(int team1, int team2) {
	if (team1 == 5 && team2 == 6) {
		for (int i = 0; i < 4; i++) {
			if (check(i)) {
				N[i] = true;
			}
		}
		return;
	}
	for (int k = 1; k <= 3; k++) {
		int next1 = team1, next2 = team2 + 1;
		if (team2 == 5) {
			next1++;
			next2 = next1 + 1;
		}
		if (k == 1) { // team1 win
			temp[team1][WIN]++;
			temp[team2][LOSE]++;

		}
		if (k == 2) { // team1 lose
			temp[team1][LOSE]++;
			temp[team2][WIN]++;

		}
		if (k == 3) { // team1 draw
			temp[team1][DRAW]++;
			temp[team2][DRAW]++;
		}
		solve(next1, next2);
		// 값들 모두 초기화.
		
		if (k == 1) {
			temp[team1][WIN]--;
			temp[team2][LOSE]--;

		}
		if (k == 2) {
			temp[team1][LOSE]--;
			temp[team2][WIN]--;

		}
		if (k == 3) {
			temp[team1][DRAW]--;
			temp[team2][DRAW]--;
		}
	}
}
// 모든 경우의 수를 배열 temp에 넣음.
// 3가지 경우의 수
// 


bool check(int index) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			if (temp[i][j] != input[index][i][j]) return false;
		}
	}
	return true;
}
