#include <string>
#include <vector>
using namespace std;

int N,M,CNT;
vector< vector<int> > v1,v2;

void Rotate(){
    vector<vector<int>> tmp(M,vector<int>(M,0));
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++){
            tmp[j][M-i-1]=v1[i][j];
        }
    v1=tmp;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    v1=key; v2=lock;
    M=v1.size(); N=v2.size();
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            if(v2[i][j]==0) CNT++;
        }
    
    for(int r=0;r<4;r++){
        for(int i=-20;i<=20;i++){
            for(int j=-20;j<=20;j++){
                int cnt=0;
                bool flag=true;
                for(int y=0;y<M;y++){
                    for(int x=0;x<M;x++){
                        int ny=i+y; int nx=j+x;
                        if(0<=ny&&ny<N&&0<=nx&&nx<N){
                            if(v2[ny][nx]==1&&v1[y][x]==1) flag=false;
                            else if(v2[ny][nx]==0&&v1[y][x]==1) cnt++;
                        }
                    }
                }
                if(cnt==CNT&&flag) return true;
            }
        }
        Rotate();
    }
    return false;
}
