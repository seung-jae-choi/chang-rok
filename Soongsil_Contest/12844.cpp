#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, m, t, a, b, c;
int ans;
string arr[500001];
string s;

string toTwocomplement(int x) {
	string str = "";
	while (x > 0) {
		int tmp = x % 2; x = x / 2;
		str = to_string(tmp)+str;
	}
	return str;
}

int toTencomplement(string s) {
	int size = s.size();
	int tmp(0),p(1);
	for (int i = size - 1; i >= 0; i--) {
		
		tmp += (s[i]-'0') * p;
		p *= 2;
	} 
	return tmp;
}

string check(string s1, string s2) {
	int size1 = s1.size();
	int size2 = s2.size();
	int size;
	string tmp = "";
	if (size1 < size2) {
		for (int i = 0; i < size2 - size1; i++) {
			s1 = '0' + s1;
		}
		size = size2;
	}
	else {
		for (int i = 0; i < size1 - size2; i++) {
			s2 = '0' + s2;
		}
		size = size1;
	}
	for (int i = 0; i < size; i++) {
		if (s1[i] != s2[i]) tmp = tmp + '1';
		else tmp = tmp + '0';
	}

	return tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s = toTwocomplement(num);
		arr[i] = s;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (t == 1) {
			cin >> a >> b >> c;
			string tmp = toTwocomplement(c);
			for (int j = a; j <= b; j++) {
				arr[j] = check(tmp, arr[j]);
			}
			
		}
		else {
			cin >> a >> b;
			string tmp = arr[a];
			for (int j = a+1; j <= b; j++) {
				tmp = check(tmp, arr[j]);
			}
			cout << toTencomplement(tmp) << "\n";
		}
	}
	return 0;
}
