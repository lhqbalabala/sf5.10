#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int w[maxn];
int c[maxn];
int dp[maxn];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>w[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=c[i];j<=m;j++){
			cout<<"����"<<i+1<<"����Ʒ���� ";
			cout<<" ����ǰ:"<<"dp"<<"["<<j<<"]="<<dp[j]<<" "; 
			dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
			cout<<"���º�:"<<dp[j]<<endl;
		}
	}
	cout<<"\n�������Ϊ : "; 
	cout<<dp[m]<<endl;
} 
/*
8 20
14 9
9 6
12 8
5 9
11 6
2 1
14 8
6 4
*/
