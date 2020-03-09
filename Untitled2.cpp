#include <iostream> 
#include <math.h>
 #include <string.h>
 #include <algorithm>
 #include <stdlib.h>
 using namespace std;
 int a[105][105]; 
int n;
 int dp[105]; 
int b[105];
 int sum; 
int main() { while(scanf("%d",&n)!=EOF) { sum=0;
 for(int i=1;i<=n;i++) 
{ for(int j=1;j<=n;j++)
 { scanf("%d",&a[i][j]); 
    }
 }
 for(int i=1;i<=n;i++) { 
     memset(b,0,sizeof(b));                
memset(dp,0,sizeof(dp)); 
for(int k=i;k<=n;k++) 
{
 for(int j=1;j<=n;j++)
 { 
b[j]+=a[k][j];
 if(dp[j-1]>=0)
 dp[j]=dp[j-1]+b[j]; 
else dp[j]=b[j];
 if(sum<dp[j]) 
sum=dp[j]; } } } printf("%d\n",sum); } return 0; }
