const int MAXN=1000000;
int f[MAXN];
void init(){
	memset(f,-1,sizeof f);
}
int getf(int x) return f[x]<0?x:f[x]=getf(f[x]);
void merge(int x,int y){
	x=getf(x),y=getf(y);
	if(x!=y){
		if(-f[x]<-f[y]) swap(x,y);
		f[x]+=f[y];
		f[y]=x;
	}
}
