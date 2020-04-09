#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n,nr,nc,r,c,x,y;
ll a[51][51],b[2][51][51],ans(0);

int main() {
	vector< pair<int,int> > arr;
	cin >> n;
	cin >> nr >> nc;
	for(int i=0;i<nr;i++)
		for(int j=0;j<nc;j++){
			cin>> a[i][j];
		}
	n--;
	while(n--){
		cin>>r>>c;
		if(nc!=r){
			cout<<-1;
			exit(0);
		}
		for(int i=0;i<nr;i++)
			for(int j=0;j<nc;j++){
				b[0][i][j] =  a[i][j];
			}
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++){
				cin>>b[1][i][j];
			}
		for(int i=0;i<nr;i++)
			for(int j=0;j<c;j++){
				a[i][j]=0;
				for(int k=0;k<nc;k++){
					a[i][j] += (b[0][i][k]*b[1][k][j]) % mod;
				}
				a[i][j] %= mod;
			}
		nc = c;
	}
	for(int i=0;i<nr;i++){
		for(int j=0;j<nc;j++){
			ans = (ans+a[i][j]) % mod;
		}
	}
	cout<<ans;
	
	return 0;
}
