#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int count(string s){
	int c=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			c++;
		}
	}
	return c;
}
int findMaxForm(vector<string>& strs, int m, int n) {
     int dp[m+1][n+1];
     memset(dp,0,sizeof(dp));
     for(int k=0;k<strs.size();k++){
     	string curr = strs[k];
     	int zeros = count(curr);
     	int ones = curr.size()-zeros;
     	for(int i = m;i>=zeros;i--){
     		for(int j=n;j>=ones;j--){
     			dp[i][j] = max(dp[i][j],dp[i-zeros][j-ones]+1);
     			cout<<dp[i][j]<<endl;
     		}
     	}
     }
     return dp[m][n]; 
}
int main(){
	int m,n;
	m =3;n=2;
	vector<string> strs = {"10", "0001", "111001", "1", "0"};
	cout<<findMaxForm(strs,m,n)<<endl;
	return 0;
}