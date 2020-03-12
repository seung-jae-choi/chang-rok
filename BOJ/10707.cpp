#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a, b, c, d, p;

int main()
{
	cin >> a >> b >> c >> d >> p;

	int sum1, sum2;
	sum1 = a * p;
	sum2 = b;
	if (p > c) {
		sum2 += (p - c) * d;
	}
	int ans;
	(sum1 > sum2) ? ans=sum2 : ans=sum1;
	cout << ans;
	return 0;
}
