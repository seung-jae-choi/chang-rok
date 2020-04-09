#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
 
typedef long long ll;
const ll mod = 1e9 + 7;
ll N,A,D,H,MA,MD,MH,Ap,Aa,Dp,Da,Hp,Ha;
ll adp[101],ddp[4],hdp[1001];
 
ll solv(ll a, ll b, ll c){
	ll ret = 1;
	while(b){
		if(b%2==1) ret = (ret*a)%c;
		a=(a*a)%c;
		b/=2;
	}
	return ret;
}
 
void upgrade(){
	if(adp[MA]==-1) adp[MA] = ((solv(MA,Ap,100)+Aa)%100)+1;
	if(ddp[MD]==-1) ddp[MD] = ((solv(MD,Dp,3)+Da)%3)+1;
	if(hdp[MH]==-1) hdp[MH] = ((solv(MH,Hp,1000)+Ha)%1000)+1;
	MA = adp[MA];
	MD = ddp[MD];
	MH = hdp[MH];
}
 
 
int main() {
	memset(adp,-1,sizeof(adp));
	memset(ddp,-1,sizeof(ddp));
	memset(hdp,-1,sizeof(hdp));
	cin>>N;
	cin>>A>>D>>H;
	cin>>MA>>MD>>MH;
	cin>>Ap>>Aa>>Dp>>Da>>Hp>>Ha;
	
	for(int i=0;i<N;i++){
 
		ll p = ceil(1.0 * MH / max(A-MD,(ll)1));
		ll m = ceil(1.0 * H / max(MA-D,(ll)1));
		if(p>m){
			cout<<-1;
			exit(0);
		}
		A+=MA; D+=MD; H+=MH;
		upgrade();
	}
	cout<<A%mod<<" "<<D%mod<<" "<<H%mod;
	return 0;
}
