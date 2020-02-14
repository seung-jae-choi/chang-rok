#include<iostream>
#include<cmath>
using namespace std;

//step 1 : 1번에 있는 n-1개의 원판을 2번으로 이동
//step 2 : 1번에 있는 1개의 원판을 3번으로 이동
//step 3 : 2번에 있는 원판을 3번으로 이동.

// count 
// 1->2로 옮기는게 An번.
// 1->3로 옮기는게 1번 (n+1번째)
// 2->3로 옮기는게 An번.
// --> A(n+1) = 2*An + 1
// --> A(n+1) + 1 = 2(An + 1)


void moveHanoi(int num, int start, int to, int end);


int main()
{
	int num,cnt;
	cin >> num;
	cnt = pow(2, num) - 1;
	cout << cnt << endl;
	moveHanoi(num, 1, 2, 3);
	return 0;
}

void moveHanoi(int num, int start, int to, int end) {
	
	if (num == 1) {
		cout << start << " " << end << endl;
	}
	else {
		moveHanoi(num - 1, start, end, to);
		cout << start << " " << end << endl;
		moveHanoi(num - 1, to, start, end);
	}
}
