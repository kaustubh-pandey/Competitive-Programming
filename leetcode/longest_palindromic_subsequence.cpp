#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
//Memory limit exceeded for string length 1000
// int f(string s,int i,int j,int dp[][1000]){
// 	if(i>j){
// 		return 0;
// 	}
// 	if(i==j){
// 		return 1;
// 	}
// 	if(dp[i][j]!=-1){
// 		return dp[i][j];
// 	}
// 	if(s[i]==s[j]){
// 		return dp[i][j]=f(s,i+1,j-1,dp)+2;
// 	}
// 	return dp[i][j]=max(f(s,i+1,j,dp),f(s,i,j-1,dp));
// }
// int longestPalindromeSubseq(string s) {
//     int n=s.size();
//     int dp[1000][1000];
//     memset(dp,-1,sizeof(dp));
//     return f(s,0,n-1,dp);
// }
//
 int longestPalindromeSubseq(string s) {
        int n=s.size();
        int dp[1005][1005];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                } 
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
int main(){
	string s="bbab";
	cout<<longestPalindromeSubseq(s)<<endl;
	return 0;
}