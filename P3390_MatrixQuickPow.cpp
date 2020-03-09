#include <iostream>
#define ll long long
#define MOD 1000000007

using namespace std;

struct Matrix{
	ll m[101][101];
};


ll n,k,num;
Matrix a,e;

Matrix mul(Matrix x,Matrix y){
	Matrix cur;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cur.m[i][j]=0;
		}
	}
	//go though our finalMartix
	//each one of our finalMartix
	//need to go though two other array
	//so O(n^3)
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				cur.m[i][j]=cur.m[i][j]%MOD+x.m[i][k]*y.m[k][j]%MOD;
			}
		}
    }
    //current Martix
	return cur;
}

Matrix pow(Matrix b,ll p){
	//equal to int ans=1
	//e is our special matrix
	Matrix ans=e;
	while(p){
		if(p&1){
			//ans*=b;
			ans=mul(ans,b);
		}
		//b*=b;
		b=mul(b,b);
		p>>=1;
	}
	return ans;
}

int main(){
	
	cin>>n>>k;
	//input -> martix a
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			cin>>a.m[i][j];
		}
	}
	
	//get our "1"
	//Martix e times any Martix equals that Martix
	for(int i=0;i<n;i++){
		e.m[i][i]=1;
	}
	
	//POWER IT!
	Matrix ans=pow(a,k);	
	
	//output
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<ans.m[i][j]%MOD<<" ";
		cout<<endl;
	}
	
	return 0;
}
