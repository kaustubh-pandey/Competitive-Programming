#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
string subtract(string a,string b){
    if(a.size()<b.size()){
        return "-1";
    }
    int flag=1;
    for(int i=b.size()-1,j=a.size()-1;i>=0 && j>=0;i--,j--){
        if(a[j]!=b[i]){
            flag=0;
            break;
        }
    }
    if(flag){
        return a.substr(0,a.size()-b.size());
    }
    return "-1";
}
bool recurse(string s,unordered_map<string,int> &m,vector<string>& wordDict){
    if(m[s]==1){
        return true;
    }
    if(m[s]==2){
        return false;
    }
    if(s==""){
        return true;
    }
    string tmp;
    bool res=false;
    for(auto word:wordDict){
        tmp = subtract(s,word);
        //cout<<tmp<<endl;
        if(tmp!="-1"){
            res = res||recurse(tmp,m,wordDict);
            if(res){
                return m[s]=true;
            }
        }
    }
    m[s]=(res)?1:2;
    return  res; 
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,int> m;
    for(auto x:wordDict){
        m[x]=1;
    }
    return recurse(s,m,wordDict);
}
/*
bool recurse(string s,unordered_map<string,int> &m){
    //cout<<s<<endl;
    if(m[s]==1){
        return true;
    }
    else if(m[s]==2){
        return false;
    }
    string tmp="";
    bool res=false;
    for(int i=s.size()-1;i>=0;i--){
        //cout<<"#"<<tmp<<endl;
        if(m[tmp]==1){
          res = res  || recurse(s.substr(0,i+1),m);
          if(res){
            return m[s]=1;
          }   
        }
        tmp = s[i]+tmp;
    }
	   m[s]=(res)?1:2;
    return  res; 
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,int> m;
    for(auto x:wordDict){
        m[x]=1;
    }
    return recurse(s,m);
}
*/
int main(){
	string s= "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	vector<string> wordDict={"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	cout<<wordBreak(s,wordDict)<<endl;
	return 0;
}


/*
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
*/