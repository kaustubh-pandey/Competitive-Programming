#include <bits/stdc++.h>
using namespace std;

string reduce(char a[],int n){
	string s="";
	for(int i=0;i<n-1;i++){
		if(a[i]!=a[i+1]){s+=a[i];}
	}
	s+=a[n-1];
	return s;
}
int lcs(string a,string b,int n,int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	return dp[n][m];
}
int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		char x[n+1],y[m+1];
		scanf("%s",x);
		scanf("%s",y);
		string a,b;
		a=reduce(x,n);
		b=reduce(y,m);
		//cout<<a<<endl;
		cout<<a.length()+b.length()-lcs(a,b,a.length(),b.length())<<endl;
	}

	return 0;
}