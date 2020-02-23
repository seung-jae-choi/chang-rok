// 증명은 못하겠지만 2의 거듭제곱이 아니면 무한 루프 돌음.

#include<iostream>
#include<math.h>
using namespace std;

int t;

long long n;
bool flag;

int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		flag = true;
		while (n>=1) {
			if (n == 1) {
				flag = true;
				break;
			}
			if (n % 2 == 0) n /= 2;
			else {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "#" << i << " " << "YES" << "\n";
		else
			cout << "#" << i << " " << "NO" << "\n";
	}
	return 0;
}
