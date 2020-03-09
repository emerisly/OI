#include<iostream>
#include<cstdio>

using namespace std;

int a[10001][10001];

int main(){
	int n,x,y;
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=4;++j)
		cin>>a[i][j];
	}
	cin>>x>>y;
	for(int i=n;i>=1;--i){
		if(a[i][1]<=x&&a[i][2]<=y&&(a[i][1]+a[i][3]>=x)&&(a[i][2]+a[i][4]>=y)){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
} 
