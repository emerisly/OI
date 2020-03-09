#include<iostream>
#include<string>

using namespace std;
int n,ans=0;
string str;

int main(){
	char a;
	cin>>n>>a;
	for(int i=1;i<=n;i++) str+=to_string(i);
	for(int i=0;i<str.size();i++){
		if(str.at(i)==a) ans++;
	}
	cout<<ans;
	return 0;
} 
