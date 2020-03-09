#include<iostream> 
#include<stdio.h>
using namespace std;

void quickSort(int arr[],int left,int right){
	int i=left,j=right;
	int temp;
	int piv=arr[(left+right)/2];
	while(i<=j){
		while(arr[i]<piv) i++;
		while(arr[j]>piv) j--;
		if(i<=j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;j--;
		}
	}
	if(left<j) quickSort(arr,left,j);
	if(i<right) quickSort(arr,i,right); 
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int r=sizeof(a)/sizeof(a[0]);
	quickSort(a,0,r-1);
	for(int x:a) cout<<x<<" ";
	return 0;
}
