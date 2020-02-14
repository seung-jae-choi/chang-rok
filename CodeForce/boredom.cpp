// 틀린접근

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int sum(0);
vector<int> v;

void Input() {
	int num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
}

void choice(int idx) {
	if(idx < n)
		sum += v[idx];
	if (idx+1 >= n)
		return;
	
	if (v[idx] - 1 == v[idx+1])
		choice(idx+2);
	else
		choice(idx+1);
}

bool cmp(int a, int b) {
	if (a > b) return true;
	else
		return false;
}
int main()
{
	Input();
	sort(v.begin(), v.end(),cmp); // 내림차순 정렬
	choice(0);
	cout << sum;

	return 0;
}

//***** ex *****
// 5
// 3 2 2 2 2  
// 같은 예제에선 greedy 적용 안됨.
