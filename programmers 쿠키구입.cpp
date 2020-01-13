#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int sum(int idx1,int idx2, vector<int> cookie){
    int sum(0);
    for(int i=idx1;i<=idx2;i++){
        sum+=cookie[i];
    }
    return sum;
}

int solution(vector<int> cookie) {
    int answer = 0;
    int N = cookie.size();
    int sum1(0),sum2(0);
    for(int i=0;i<N;i++){
        for(int m=i+1;m<N-1;m++){
            sum1=sum(i,m,cookie);
            for(int k=m+1;k<=N;k++){
                sum2=sum(m+1,k,cookie);
                if(sum1==sum2) {
                    answer=max(answer,sum1);
                }
                else if(sum1<sum2) break;
            }
        }
    }
    return answer;
}
