#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n,m,t,p;
int stop[11];
vector< pair<int,int> > pii;
deque< pair<int,int> > dq;

int main() {
	cin>>n>>m;
	memset(stop,0,sizeof(stop));
	for(int i=1;i<=m;i++){
		cin>>t>>p;
		pii.push_back({t,p});
	}
	int cur=0;
	for(int i=1;i<1005;i++){
		int pos;
		int f;
		while(!dq.empty()&&dq.front().second<=i)
			dq.pop_front();
		while((dq.empty()||dq.back().first<n)&&pii[cur].first<=i){
			if(dq.empty()){
				pos=1;
			}
			else{
				pos=dq.back().first+1;
			}
			f= i + pii[cur].second;
			if(cur==m-1){
				cout << pos;
				return 0;
			}
			dq.push_back({pos,f});
			cur++;
		}
		
	}
	
	return 0;
}
