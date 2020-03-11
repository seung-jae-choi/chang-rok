#include <iostream>
#include <algorithm>
using namespace std;

int d[1001];
int p[10001];
int n;

int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	d[0]=p[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			d[i]=max(d[i-j]+p[j],d[i]);
		}
	}
	cout<<d[n];
	return 0;
}
