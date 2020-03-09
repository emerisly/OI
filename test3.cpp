#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
char c;
int a,b,x,y,sec[10000000][2],cnt=0;
 int main()
 {
     while(cin>>c && c!='E'){
	 if (c=='W'){a++;x++;}
     if (c=='L'){b++;y++;}
	 if((a>=11&&a-b>=2)||(b>=11&&b-a>=2)){printf("%d:%d\n",a,b);a=0;b=0;};
	 if((x>=21&&x-y>=2)||(x>=21&&x-y>=2)){sec[cnt][0]=x;sec[cnt][1]=y;x=0;y=0;cnt++;};
	}
	printf("%d:%d\n\n",a,b);
    for(int i=0;i<cnt;i++) printf("%d:%d\n",sec[i][0],sec[i][1]);
    printf("%d:%d",x,y);
     return 0;
}
