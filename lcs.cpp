#include<bits/stdc++.h>
using namespace std;
char a[1010];
char b[1010];
int len1;
int len2;
int dp[1010][1010];
int vis[1010][1010];
void lcs()
{   int i,j;
    for(i=1; i<=len1; i++)
    {
        for(j=1; j<=len2; j++)
        {
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                printf("两字符串在%d,%d处相等,dp[%d][%d]=dp[%d][%d]+1=%d\n",i,j,i,j,i-1,j-1,dp[i][j]);
				vis[i][j]=0;}
            else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                printf("在%d,%d处，dp[%d][%d]>dp[%d][%d],dp[%d][%d]=dp[%d][%d]+1=%d\n",i,j,i-1,j,i,j-1,i,j,i-1,j,dp[i][j]);
				vis[i][j]=1;}
            else{
                dp[i][j] = dp[i][j-1];
                printf("在%d,%d处，dp[%d][%d]<dp[%d][%d],dp[%d][%d]=dp[%d][%d]+1=%d\n",i,j,i-1,j,i,j-1,i,j,i,j-1,dp[i][j]);
				vis[i][j]=-1;}
        }
    }
}
void print(int x,int y){
	if(x==0&&y==0)return;
	if(vis[x][y]==0){
		print(x-1,y-1);
		cout<<a[x-1];
	}
	else if(vis[x][y]==1){
		print(x-1,y);
	}
	else{
		print(x,y-1);
	}
}
int main(){
	scanf("%s %s",a,b);
	len1=strlen(a);
	len2=strlen(b);
	lcs();
	cout<<"最长公共子序列长度为:\n"; 
	cout<<dp[len1][len2]<<endl;
	cout<<"最长公共子序列为:\n" ;
	print(len1,len2);
	cout<<endl;
} 
