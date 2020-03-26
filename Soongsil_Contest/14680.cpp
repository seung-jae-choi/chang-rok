//comment : 1. 문제를 제대로 안읽어서 증상 하나 이상 해결 못하면 "you died" 출력하는 부분을 못봄.
//          2. 약 이름과 효능이 0이 될 수 있는데, 이 부분을 생각하지 못하고 medicine배열을 0으로 초기화 하였다.

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

int n,r;
bool flag;
int medicine[105]; //medicine[1]=9 --> 9번은 약 이름, 1은 효능
vector< vector<int> > vi;
vector<int> tmp;
vector<int> print;
int main()
{
	cin >> n;
	memset(medicine, -1, sizeof(medicine));
	for (int i = 0; i < n; i++) {
		int f, s;
		cin >> f >> s;
		medicine[f] = s;
	}
	cin >> r;
	for (int i = 0; i < r; i++) {
		int num;
		cin >> num;
		tmp.resize(num);
		for (int j = 0; j < num; j++) {
			cin >> tmp[j];
		}
		vi.push_back(tmp);
		tmp.clear();
	}

	for (int i = 0; i < r; i++) {
		int size = vi[i].size();
		print.resize(size);
		flag = true;
		for (int j = 0; j < size; j++) {
			int ill = vi[i][j];
			if (medicine[ill] == -1) {
				flag = false;
				break;
			}
			else {
				print[j] = medicine[ill];
			}
		}
		if (flag){
			for (int k = 0; k < size; k++) {
				cout << print[k] << " ";
			}
		}
		else {
			cout << "YOU DIED";
		}
		print.clear();
		cout << "\n";
	}
	return 0;
}
