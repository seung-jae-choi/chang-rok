#include<iostream>
#include<cmath>
using namespace std;

// [0,0] -> [0,1] -> [1,0] -> [1,1]
int n,r,c;
int size;
int x, y;
int cnt(0);
void z(int size,int y,int x);

int main()
{
	cin >> n >> r >> c;
	int size1;
	size1 = pow(2, n);
	z(size1, 0, 0);
	return 0;
}

void z(int size,int y,int x) {
	if (size == 2) {
		if (y == r && x == c) {
			cout << cnt << endl;
			return;
		}
		cnt++;
		if (y == r && x + 1 == c) {
			cout << cnt << endl;
			return;
		}
		cnt++;
		if (y + 1 == r && x == c) {
			cout << cnt << endl;
			return;
		}
		cnt++;
		if (y + 1 == r && x + 1 == c) {
			cout << cnt << endl;
			return;
		}
		cnt++;
		return;
	}
	
	
	z(size / 2, y, x); // 1사분면
	z(size / 2, y, x + size / 2); // 2사분면
	z(size / 2, y + size / 2, x); // 3사분면
	z(size / 2, y + size / 2, x + size / 2); // 4사분면
}
