#include<iostream>
#include<string>
using namespace std;

int t;

string str1, str2;

int main()
{
	int h1, m1, s1;
	int h2, m2, s2;
	int h3, m3, s3;
	int sum1, sum2;
	string a1, a2, a3;
	int ans;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> str1;
		cin >> str2;
		h1 = stoi(str1.substr(0, 2));
		m1 = stoi(str1.substr(3, 2));
		s1 = stoi(str1.substr(6, 2));
		h2 = stoi(str2.substr(0, 2));
		m2 = stoi(str2.substr(3, 2));
		s2 = stoi(str2.substr(6, 2));
		sum1 = h1 * 60 * 60 + m1 * 60 + s1;
		sum2 = h2 * 60 * 60 + m2 * 60 + s2;
		if (sum2 - sum1 >= 0) { //약속시간이 같은날
			ans = sum2 - sum1;
			h3 = ans / 3600; ans = ans % 3600; a1 = to_string(h3);
			if (h3 == 0) a1 = "00";
			else if (h3 < 10) a1 = "0" + a1;
			m3 = ans / 60; ans = ans % 60; a2 = to_string(m3);
			if (m3 == 0) a2 = "00";
			else if (m3 < 10)a2 = "0" + a2;
			s3 = ans; a3 = to_string(s3);
			if (s3 == 0) a3 = "00";
			else if (s3 < 10)a3 = "0" + a3;
			cout << "#" << i << " " << a1 << ":" << a2 << ":" << a3 << "\n";
		}
		else {
			ans = 24 * 60 * 60 - sum1 + sum2;
			h3 = ans / 3600; ans = ans % 3600; a1 = to_string(h3);
			if (h3 == 0) a1 = "00";
			else if (h3 < 10) a1 = "0" + a1;
			m3 = ans / 60; ans = ans % 60; a2 = to_string(m3);
			if (m3 == 0) a2 = "00";
			else if (m3 < 10) a2 = "0" + a2;
			s3 = ans; a3 = to_string(s3);
			if (s3 == 0) a3 = "00";
			else if (s3 < 10) a3 = "0" + a3;
			cout << "#" << i << " " << a1<< ":" << a2 << ":" << a3 << "\n";
		}
	}
	return 0;
}
 
