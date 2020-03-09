#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
char c;
int a,b,x,y,sec[1000000][2],cnt=0;
int main(){
	while(cin>>c&&c!='E'){
		if(c=='W'){a++;x++;}
		if(c=='L'){b++;y++;}
		if((a>=11||b>=11)&&abs(b-a)>=2)
		{cout<<a<<":"<<b<<endl;a=0;b=0;}
		if((x>=21||y>=21)&&abs(y-x)>=2)
		{sec[cnt][0]=x;sec[cnt][1]=y;x=0;y=0;cnt++;}
	}
	printf("%d:%d\n\n",a,b);
    for(int i=0;i<cnt;i++) printf("%d:%d\n",sec[i][0],sec[i][1]);
    printf("%d:%d",x,y);
	return 0;
}
