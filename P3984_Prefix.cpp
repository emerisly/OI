#include <iostream>
using namespace std;

int main(){
	int a,b,temp,ans;
	cin>>a>>b;
	int day[a+3],dif[a+3];
	day[0]=0;
	for(int i=1;i<=a;i++){
		cin>>temp;
		day[i]=temp;
		dif[i]=temp-day[i-1];
	}
	ans=b;
	for(int i=2;i<=a;i++){
		dif[i]>b?ans+=b:ans+=dif[i];
	}
	cout<<ans;
	
	return 0;
}
