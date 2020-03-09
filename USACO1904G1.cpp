#include <bits/stdc++.h>

using namespace std;

int N,K,INF=99999999;
int a[405],dp[405][405],maxx[405][405],range[405][405];

int getRange(int l,int r,int k){
	int cur=0,sum=0;
	for(int i=l;i<=r;i++){
		if(a[i]+cur>k)
			cur=a[i];
		else
			cur=a[i]+cur;
		sum+=k-cur;
	}
	return sum;
}

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++)
		cin>>a[i];
	
	//find max
	for(int i=0;i<N;i++){
		int m=0;
		for(int j=i;j<N;j++){
			m=max(m,a[j]);
			maxx[i][j]=m;
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=i;i<N;i++){
			range[i][j]=getRange(i,j,maxx[i][j]);
		}
	}
	
	for(int i=0;i<K;i++){
		for(int j=0;j<N;j++){
			if(i>=j){
				dp[i][j]=-1;
				continue;
			}
			if(i==0)
				dp[i][j]=range[0][j];
			else{
				int result=INF;
				for(int k=0;k<j;k++){
					result=min(dp[i-1][k]+range[k+1][j],result);
				}
				dp[i][j]=result;
			}
		}
	}
	
	
	
}
