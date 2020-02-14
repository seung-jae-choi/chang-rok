using namespace std;

long long solution(int w,int h)
{
	long long sum=(long long)w * (long long)h;
    int x(w),y(h);
    int temp,gcd;
    while(h!=0){
        temp = w%h;
        w=h;
        h=temp;
    }
    gcd=w;
    
	return sum-gcd*((x/gcd)+(y/gcd)-1);
}
