#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int x;
string str;

int main()
{
	cin >> x;
	cin >> str;
	string tmp = str;
	int size = str.size();
	int temp = size;
	if (size % 2 == 0) size = size / 2 - 1;
	else size = size / 2;
	int cnt(0);
	while (true)
	{
		cnt++;
		for (int i = size * 2 - 1; i >= 1; i -= 2) {
			string s = str.substr(i, 1);
			str.insert(temp, s);
			str.erase(i, 1);
			
		}
		if (tmp == str) break;
	}
	x = x % cnt;
	while (x)
	{

		for (int i = size * 2 - 1; i >= 1; i -= 2) {
			string s = str.substr(i, 1);
			str.insert(temp, s);
			str.erase(i, 1);
		}
		x--;
	}
	cout << str;
	return 0;
}
