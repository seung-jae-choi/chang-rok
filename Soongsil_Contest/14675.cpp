#include<iostream>
#include<cstring>
using namespace std;

int n,a,b,q,t,k;

int map[100001];

bool check(int v){
    if(map[v]>1) return false;
    return true; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(map,0,sizeof(map));
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        map[a]++;
        map[b]++;
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>t>>k;
        if(t==1){
            if(check(k)){
                cout<<"no\n";
            }
            else
                cout<<"yes\n";
        }
        else if(t==2){ //tree구조면 단절선은 항상 yes임.
            cout<<"yes\n";
        }
    }
    return 0;
}
