#include<iostream>
using namespace std;
int main(){
	int a,i=0,j=0;
	cin>>a;
	while(j<a) j+=++i;
	i%2==1?cout<<j-a+1<<"/"<<i+a-j:cout<<i+a-j<<"/"<<j-a+1;
	return 0;
}
