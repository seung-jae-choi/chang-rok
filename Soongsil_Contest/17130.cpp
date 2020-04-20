#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;
int r,c;
int dp[1001][1001];
int map[1001][1001];

int main()
{    
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>N>>M;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++){
    	string s;
    	cin>>s;
    	for(int j=0;j<M;j++){
    		if(s[j]=='R'){
    			r=i; c=j;
    		}
    		else if(s[j]=='C') map[i][j]=1;
    		else if(s[j]=='O') map[i][j]=2;
    		else if(s[j]=='#') map[i][j]=-1;
    	}
    }
    int ans=-1;
    dp[r][c]=0;
    for(int j=c+1;j<M;j++){
    	for(int i=0;i<N;i++){
    		if(map[i][j]==-1) continue;
    		if(i-1>=0){
    			if(dp[i-1][j-1]!=-1){
    				if(map[i][j]==1){
    					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    				}
    				else dp[i][j]=max(dp[i-1][j-1],dp[i][j]);
    			}
    		}
    		if(i+1<N){
    			if(dp[i+1][j-1]!=-1){
    				if(map[i][j]==1){
    					dp[i][j]=max(dp[i][j],dp[i+1][j-1]+1);
    				}
    				else dp[i][j]=max(dp[i+1][j-1],dp[i][j]);
    			}
    		}
    		if(dp[i][j-1]!=-1){
    			if(map[i][j]==1){
    					dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
    				}
    				else dp[i][j]=max(dp[i][j-1],dp[i][j]);
    		}
    		if(map[i][j]==2){
    			ans=max(ans,dp[i][j]);
    		}
    	}
    }
    cout << ans;
    return 0;
}
