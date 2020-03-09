#include<bits/stdc++.h>

using namespace std;

int T,max,code[30],arr[30],prefix[30],shoot,charge;

int count(){
	
}


int main(){
	cin>>T;
	prefix[0]=arr[0]=1;
	for(int i=1;i<30;i++){
		arr[i]=2*arr[i-1];
		prefix[i]+=arr[i];
	}
	for(int t=1;t<=T;t++){
		cin>>max;
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			code[i]=s.at(i)=='S'?1:0;
			s.at(i)=='S'?shoot++:charge++;
		}
		
		
		
		
		
	}
	
	
	return 0;
}
