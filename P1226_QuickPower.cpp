#include<iostream>
using namespace std;

long b,p,k,ans;

long quickPow(long b,long p,long k){
	long ans=1;
	while(p){
		if(p&1){
			ans*=b;
			ans%=k;
		}
		b*=b;
		p>>=1;
	}
	return ans;
}

int main(){
	cin>>b>>p>>k;
	ans=quickPow(b,p,k);
	ans%=k;
	cout<<b<<"^"<<p<<" mod "<<k<<"="<<ans;
	
	return 0;
}
 
