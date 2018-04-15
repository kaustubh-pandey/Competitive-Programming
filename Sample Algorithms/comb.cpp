#include <bits/stdc++.h>
using namespace std;
double fact(int n,int *dp){
	if(dp[n]!=-1){
		return dp[n];
	}
	if(n==0||n==1){
		return 1;
	}
	else{
		return dp[n]=fact(n-1,dp)*n;
	}
}
double comb(int n,int r,int *m){
	if(m[r]!=-1){
		return m[r];
	}
	if(m[n-r]!=-1){
		return m[n-r];
	}
	int *dp=new int[n+1];
	int *dp2=new int[n+1];
	int *dp3=new int[n+1];
	for(int i=0;i<=n;i++){
		dp[i]=-1;
		dp2[i]=-1;
		dp3[i]=-1;
	}
	return m[r]=fact(n,dp)/(fact(n-r,dp2)*fact(r,dp3));
}
int main(){
int n,k;
cin>>n>>k;
int *m=new int[n+1];
for(int i=0;i<=n;i++){
	m[i]=-1;
}
//if k>=ceil(n+1)/2 do direct sum from k to n
long long int sum=0;
if(k>=ceil((n+1)/2)){
	for(int r=k;r<=n;r++){
		sum+=(long long int)comb(n,r,m)%(1000000000+7);
	}
}
else{
	for(int r=0;r<k;r++){
		sum+=(long long int)comb(n,r,m)%(1000000000+7);
	}
	sum=((1<<n)-sum)%(1000000000+7);
}
cout<<sum%(1000000000+7)<<endl;
return 0;
}