#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void print(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" \n"[i==n-1];
	}
}
int max_profit(int a[],int n){
	int min_price[n];
	int dp[n];
	min_price[0]=a[0];	
	for(int i=1;i<n;i++){
		min_price[i]=min(a[i],min_price[i-1]);
	}
	//print(min_price,n);
	dp[0]=0;
	for(int i=1;i<n;i++){
		dp[i]=max(a[i]-min_price[i],dp[i-1]);
	}
	//print(dp,n);
	return dp[n-1];
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<max_profit(a,n)<<endl;
	return 0;
}