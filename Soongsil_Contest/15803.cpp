#include<iostream>
using namespace std;

double x1,y1,x2,y2,x3,y3;
double m,m1;

int main()
{
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>x3>>y3;
	
	if(x2-x1==0){
		if(x3==x2)
			cout<<"WHERE IS MY CHICKEN?";
		else
			cout<<"WINNER WINNER CHICKEN DINNER!";
		exit(0);
	}
	else if(y2-y1==0){
		if(y3==y2)
			cout<<"WHERE IS MY CHICKEN?";
		else
			cout<<"WINNER WINNER CHICKEN DINNER!";
		exit(0);
	}
	else{
		m=(y2-y1)/(x2-x1);
		m1=(y3-y2)/(x3-x2);
		if(m==m1)
				cout<<"WHERE IS MY CHICKEN?";
		else
			cout<<"WINNER WINNER CHICKEN DINNER!";
		exit(0);
	}
	
	
	return 0;
}
