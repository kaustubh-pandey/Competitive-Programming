#include<bits/stdc++.h>
using namespace std;
//O(n^2) time and O(n^2) space
/*string longestPalindromeSubstring(string s) {
    int n=s.size();
    int dp[1005][1005];
    memset(dp,false,sizeof(dp));
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j]=true;
            }
            else if(i==j-1){
            	if(s[i]==s[j]){
            		dp[i][j]=true;	
            	}
            	else{
            		dp[i][j]=false;
            	}
            }
            else if(s[i]==s[j]){
                dp[i][j]=dp[i+1][j-1];
            } 
            else{
                dp[i][j]=false;
            }
        }
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cout<<dp[i][j]<<" \n"[j==n-1];
    	}
    }
    int res_i=0,res_j=0;
    int flag=0;
    for(int dif = n-1;dif>=0;dif--){
    	for(int i=0;i<n-dif;i++){
    		//cout<<i<<" "<<i+dif<<endl;
    		if(dp[i][i+dif]){
    			res_i=i;
    			res_j=i+dif;
    			flag=1;
    			break;
    		}
    	}
    	if(flag){
    		break;
    	}
    }
    string res="";
    for(int k=res_i;k<=res_j;k++){
    	res+=s[k];
    }
    return res;
}*/

//O(n^2) time and O(1) space
pair<int,int> expandAroundCenter(string s,int l,int r){
	while(l>=0 && r<s.size() && s[l]==s[r]){
		l--;r++;
	}
	return make_pair(l,r);
}
pair<int,int> pairMax(pair<int,int> p1,pair<int,int> p2){
	if(p1.second-p1.first-1>p2.second-p2.first-1){
		return p1;
	}
	return p2;
}
void print(pair<int,int> p){
	cout<<p.first<<" "<<p.second<<endl;
}
string longestPalindromeSubstring(string s) {
	int n=s.size();
	pair<int,int> res = {0,0};
	for(int i=0;i<n;i++){
		//print(res);
		pair<int,int> c1 = expandAroundCenter(s,i,i); //center as i
		//print(c1);
		pair<int,int> c2 = expandAroundCenter(s,i,i+1); //center between i and i+1
		//print(c2);
		res = pairMax(res,pairMax(c1,c2));
		//print(res);
	}
	string r = "";
	for(int i=res.first+1;i<res.second;i++){
		r+=s[i];
	}
	return r;
}
int main(){
	string s;
	cin>>s;
	cout<<longestPalindromeSubstring(s)<<endl;
	return 0;
}