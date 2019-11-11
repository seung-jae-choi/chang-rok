#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
// 빈 칸에 1-9넣으면서 만족하는지 검사.
// 가로, 세로, 3x3 행렬에 대해


int sudo[9][9];
vector<pair<int, int>> ary;
void Input() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> sudo[i][j];
			if (sudo[i][j] == 0)
				ary.push_back({ i,j });
		}
}
bool check_col(int col,int num) {
	for (int i = 0; i < 9; i++) {
		if (sudo[i][col] == num)
			return false;
	}
	return true;
}
bool check_row(int row,int num) {
	for (int i = 0; i < 9; i++) {
		if (sudo[row][i] == num)
			return false;
	}
	return true;
}
bool check_matrix(int row,int col, int num){
	row = row / 3;
	col = col / 3;
	for(int r=row*3;r<(row*3)+3;r++)
		for (int c = col * 3; c < (col * 3) + 3; c++) {
			if (sudo[r][c] == num)
				return false;
		}
	return true;
}
void numbering(int idx) { // 1~9까지의 숫자 넣기
	if (idx == ary.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudo[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	
	for (int num = 1; num <= 9; num++) {
		int row = ary[idx].first;
		int col = ary[idx].second;
		if (check_col(col, num) && check_row(row, num)
			&& check_matrix(row, col, num)) {
			sudo[row][col] = num;
			numbering(idx+1);
			sudo[row][col] = 0;
		}
	}
}
int main()
{
	Input();
	for (int num = 1; num <= 9; num++) {
		int row = ary[0].first;
		int col = ary[0].second;
		if (check_col(col, num) && check_row(row, num)
			&& check_matrix(row, col, num)) {
			sudo[row][col] = num;
			numbering(1);
			sudo[row][col] = 0;
		}
	}
	
	return 0;
}

// 처음에 한 실수 -> 값을 임의로 넣고 나서, 다시 되돌리지 않았음.
