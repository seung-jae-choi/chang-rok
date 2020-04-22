#include <iostream>
#include <vector>
using namespace std;

int n,start,cnt(0);
vector<int> path;
int m[200001];
bool flag[200001];

int main() {
	cin>>n;
	path.resize(n);
	for(int i=0;i<n;i++){
		cin>>path[i];
		if(i==0) start=path[i];
	}
	m[start]=-1; flag[start]=true;
	cnt++;
	for(int i=1;i<n;i++){
		int curr = path[i];
		if(!flag[curr]){
			m[curr]=path[i-1];
			flag[curr]=true;
			cnt++;
		}
	}
	cout << cnt <<"\n";
	for(int i=0;i<cnt;i++){
		cout << m[i] <<" ";
	}
	return 0;
}
