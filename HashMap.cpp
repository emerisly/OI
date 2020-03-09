#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL q=(q<<31)-1,p=9987;

void Hash(char *s) {
	LL x=233;
	//s[i]end with zero 
	for(int i=0;s[i];i++) x=(x*p+s[i])%q;
	return (int)x;
}

#define MAXN 233333
#define SIZE 1000001
struct Hash_Map{
	struct Node{
		int next,v,w;
	}e[MAXN];
	
	int cnt, head[SIZE];
	int &operator [] (int v) {
	for(int o=head[v%SIZE];o;e[o].next){
		if(e[o].v==v) return e[o].w;
	}
	
	e[++cnt]=(Node){head[v%SIZE],v,0};
	head[v%SIZE]=cnt;
	return e[cnt].w;
	}
} a; 

int main(){
	
}


















