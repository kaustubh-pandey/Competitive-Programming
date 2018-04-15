//Without repetition of any item
#include<bits/stdc++.h>
using namespace std;
int knapsack(int W,int val[],int wt[],int n){
	int i,w;
	int dp[n+1][W+1];
	for(i=0;i<=n;i++){
		for(w=0;w<=W;w++){
			if(i==0||w==0){
				dp[i][w]=0;
			}
			else if(wt[i-1]<=w){
				dp[i][w]= max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
			}
			else{
				dp[i][w]=dp[i-1][w];
			}
		}
	}
	for(int j=0;j<=n;j++){
		for(int k=0;k<=W;k++){
			printf("%d ",dp[j][k]);
		}
		cout<<endl;
	}
	return dp[n][W];

}
int main(){
	int n,i;
	cin>>n;
	int *val=new int[n];
	int *wt=new int[n];
	int W;
	cin>>W;
	for(i=0;i<n;i++){
		scanf("%d",&val[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&wt[i]);
	}
	knapsack(W,val,wt,n);
	return 0;
}