#include <iostream>

using namespace std;

int n,m,tag[10005],p1,p2,p3,ans;

int findTag(int k){
	if(tag[k]==k) return k;
	//change tag
	return tag[k]=findTag(tag[k]);
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		tag[i]=i;
	} 
	for(int i=0;i<m;i++){
		cin>>p1>>p2>>p3;
		if(p1==1) tag[findTag(p3)]=findTag(p2);
		else{
			if(findTag(p2)==findTag(p3)) cout<<"Y\n";
			else cout<<"N\n";
		}
	} 
	return 0;
}
