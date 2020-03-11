#include <iostream>
#include <algorithm>
using namespace std;

int t[16];
int p[16];
int n;
int d[16];

int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>p[i];
	}
	int result=0;
	for(int i=1;i<=n;i++){
		//i번째날 일한 경우
		if(i+t[i]<=n+1){
			d[i+t[i]]=max(d[i+t[i]],d[i]+p[i]);
			result = max(result,d[i+t[i]]);
		}
		//i번째 일 안함
		d[i+1]=max(d[i],d[i+1]);
		result = max(result,d[i+1]);
	}
	cout<<result;
	return 0;
}
