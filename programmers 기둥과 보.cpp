#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int pillar[101][101];
int beam[101][101];
int map[101][101]; // 1이면 기둥,2면 보, 3이면 둘다 있는 것.

//문제의 정렬조건
bool cmp(vector<int> a,vector<int> b){
    if(a[0]!=b[0]) return a[0] < b[0];
    else if(a[0]==b[0]&&a[1]!=b[1]) return a[1]<b[1];
    else return a[2]<b[2];
}

//기둥과 보가 존재할 수 있는지 체크
bool isBuilt(int x,int y,int target){
    if(target==0){ //기둥일 경우
        // 바닥, 아래 기둥 존재, 아래 보 존재
        if(y==0||(y>=1&&pillar[y-1][x]==1)||
          beam[y][x]==1||(x>=1&&beam[y][x-1]==1))
            return true;
        else return false;
    }
    else{
        // 아래 기둥 존재, 양 옆에 보가 연결
        if((y>=1&&pillar[y-1][x]==1||pillar[y-1][x+1]==1)
           || (x>=1&&beam[y][x-1]==1&&beam[y][x+1]==1))
            return true;
        else return false;
    }
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    // 초기화
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            pillar[i][j]=0;
            beam[i][j]=0;
            map[i][j]=0;
        }
    }
    int size = build_frame.size();
	  for(int i = 0; i < size; i++) {
		  int x = build_frame[i][0];
		  int y = build_frame[i][1];
		  int target = build_frame[i][2]; // 0:기둥,1:보
		  int act = build_frame[i][3]; //0:삭제,1:설치
		  if (act == 1) { // 설치
			  if (target == 0) {
                if(isBuilt(x,y,target)){
                    map[y][x]+=1;
                    pillar[y][x]=1;
                }
            }
		    else if(target==1){
                if(isBuilt(x,y,target)){
                    map[y][x]+=2;
                    beam[y][x]=1;
                }
            }
        }
        //삭제
        else if(act==0){
            if(target==0){
                // 일단 지운다고 가정
                pillar[y][x]=0;
                // 위에 기둥이 존재한다면
                if(pillar[y+1][x]==1 && !isBuilt(x,y+1,0)){
                       pillar[y][x]=1;    
                }
                // 기둥 위의 왼쪽에서 오는 보가 존재 한다면
                else if(x>=1&&beam[y+1][x-1]==1&&!isBuilt(x-1,y+1,1)){
                    pillar[y][x]=1;
                }
                // 기둥 위의 보가 존재 한다면
                else if(beam[y+1][x]==1&&!isBuilt(x,y+1,1)){
                    pillar[y][x]=1;
                }
                //삭제 했으므로 지움.
                else map[y][x]-=1;
            }
            else if(target==1){
                beam[y][x]=0;
                // 보의 왼쪽 위에 기둥이 존재한다면
                if(pillar[y][x]==1&&!isBuilt(x,y,0))
                    beam[y][x]=1;
                // 보의 오른쪽 위에 기둥이 존재한다면
                else if(pillar[y][x+1]==1&&!isBuilt(x+1,y,0))
                    beam[y][x]=1;
                // 보의 왼쪽에 보가 존재한다면
                else if(x>=1&&beam[y][x-1]==1&&!isBuilt(x-1,y,1))
                    beam[y][x]=1;
                // 보의 오른쪽에 보가 존재한다면
                else if(beam[y][x+1]==1&&!isBuilt(x+1,y,1))
                    beam[y][x]=1;
                // 삭제 했으므로 지움.
                else map[y][x]-=2;
            }
        }
    }
    // answer로 옮겨주기
    for(int y=0;y<=n;y++){
        for(int x=0;x<=n;x++){
            if(map[y][x]!=0){
                if(map[y][x]==1){
                    vector<int> tmp;
                    tmp.push_back(x);
                    tmp.push_back(y);
                    tmp.push_back(0);
                    answer.push_back(tmp);
                }
                else if(map[y][x]==2){
                    vector<int> tmp;
                    tmp.push_back(x);
                    tmp.push_back(y);
                    tmp.push_back(1);
                    answer.push_back(tmp);
                }
                else if(map[y][x]==3){
                    vector<int> tmp1;
                    tmp1.push_back(x);
                    tmp1.push_back(y);
                    tmp1.push_back(0);
                    answer.push_back(tmp1);
                
                    vector<int> tmp2;
                    tmp2.push_back(x);
                    tmp2.push_back(y);
                    tmp2.push_back(1);
                    answer.push_back(tmp2);
                }
            }   
        }
    }
    // 조건에 따라 
    sort(answer.begin(),answer.end(),cmp);
    return answer;
}
