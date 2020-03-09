#include<iostream>
#include<cmath>
#define MAXN 5005
#define MAXM 200005
#define INF 233333

//Prim Minimum Spanning Tree

using namespace std;

//non direction, double size
struct edge{
	int v,w,next;
}e[MAXN<<1]; 


int head[MAXM],dis[MAXN],cnt,n,m,tot=1,now=1,ans;
bool vis[MAXM];


void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}



int prim(){
	//give dis max value
	for(int i=2;i<=n;i++)
		dis[i]=INF;	
	//double path so min
	for(int i=head[1];i;i=e[i].next)
		dis[e[i].v]=min(dis[e[i].v],e[i].w);
	
	while(tot++<n){
		//MST path # == edge-1
		int minn=INF;
		vis[now]=1;//visited
		for(int i=1;i<=n;++i){
			if(!vis[i]&&minn>dis[i]){
				minn=dis[i];
				now=i;
			}
		}
		ans+=minn;
		//all edge that link to now, refresh dis
		for(int i=head[now];i;i=e[i].next){
			int v=e[i].v;
			if(dis[v]>e[i].w&&!vis[v])
				dis[v]=e[i].w;
		}
	}
	return ans;
}


int main(){
	cin>>n>>m;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	prim();
	cout<<cnt<<endl;
	cout<<ans;
	
	return 0;
}
