#include<bits/stdc++.h>
using namespace std;
string shortestPalindrome(string s) {
    int n = s.size();
    string s_new = s+"#";
    for(int i=n-1;i>=0;i--){
        s_new+=s[i];
    }
    int lps[2*n+1];
    lps[0]=0;
    for(int i=1;i<2*n+1;i++){
        int t = lps[i-1];
        while(t>0 && s_new[i]!=s_new[t]){
            t=lps[t-1];
        }
        if(s_new[i]==s_new[t]){
            t++;
        }
        lps[i]=t;
    }
    string res="";
    for(int i=n-1;i>=lps[2*n];i--){
        res+=s[i];
    }
    res+=s;
    return res;
}
int main(){
	string s= "aaaaaac";
	// for(int i=0;i<40002;i++){
	// 	s+="a";
	// }
	cout<<shortestPalindrome(s)<<endl;
	return 0;
}