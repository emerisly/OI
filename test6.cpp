#include <iostream>
using namespace std;

int main(){
	long long x=2019201913,y=2019201949;
	long long a=1,b=300;
	long long n=2019201997;
	long long ans=(x*a%n+y*b%n)%n;
	cout<<ans;
	return 0;
} 
