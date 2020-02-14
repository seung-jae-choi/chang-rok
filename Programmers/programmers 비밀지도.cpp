#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++){
        string temp="";
        int limit = pow(2,n-1);
        while(true){
            if(limit==0) break;
            if(arr1[i] < limit && arr2[i] < limit){
                temp+=" ";
                limit/=2;
            }
            else {
                temp+="#";
                if(arr1[i] >=limit)
                    arr1[i]-=limit;
                if(arr2[i] >= limit)
                    arr2[i] -=limit;
                limit/=2;
            }
        }
        answer.push_back(temp);
    }
    
    return answer;
}
