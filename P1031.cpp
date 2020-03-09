#include <iostream>
using namespace std;
//prefix sum check if move from another stack 
int main(){
	int n=0,a[10001],tot=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];tot+=a[i];
	}
	tot/=n;
	for(int i=0;i<n;i++){
		a[i]-=tot;
		if(a[i]==0) continue;
		a[i+1]+=a[i];
		cnt++;
	}
	cout<<cnt;
}

