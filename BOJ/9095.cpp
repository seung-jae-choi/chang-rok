#include<iostream>
#include<vector>
using namespace std;

vector<int> a;

/*
f(n) = f(n-1) + f(n-2) +f(n-3)
*/


int main()
{
	int array[11] = {0,1,2,4};
	int test,num;
	cin >> test;
	
	for (int i = 0; i < test; i++) {
		cin >> num;
		a.push_back(num);
		for (int j = 4; j <= num; j++) {
			array[j] = array[j - 3] + array[j - 2] + array[j - 1];
		}
	}
	for (int i = 0; i < test; i++) {
		cout << array[a[i]] << endl;
	}
	return 0;
}

