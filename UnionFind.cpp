#include <iostream>

public class UF{
	private int[] id;//id
	private int count;//components
	public UF(int N){
		//id array
		count=N;
		id=new int[N];
		for(int i=0;i<n;i++)
		id[i]=i;
	}
	public int count() return count;
	public bool connected(int p,int q) return id[p]==id[q];
	public void union(int p,int q){
		int pID=id[p];
		int qID=id[q];
		if(pID==qID) return;
		for(int i=0;i<id.length;i++){
			if(id[i]==pID) id[i]=qID;
		}
	}
	
}
