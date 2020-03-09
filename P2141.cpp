#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n],sum[n][n],ans=0,flag[20000];
	for(int i=1;i<=n;i++) cin>>a[i]; 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum[i][j]=a[i]+a[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]==sum[j][k]&&flag[a[i]]==0){
				ans++;
				flag[a[i]]=-1;
				}
			}
		}
	} 
	cout<<ans;
	return 0;
}


