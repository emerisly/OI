const int MAXN=1000000;
int f[MAXN];
void init(){
	for(int i=1;i<=n;i++)
	f[i]=i;
}
int getf(int x){
	if(f[x]==x) return x;
	else return f[x]=getf(f[x]);
}
void merge(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) f[x]=y;
}
