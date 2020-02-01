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
bool recurse(string s,unordered_map<string,int> &m,vector<string>& wordDict,string y,vector<string> &result){
    if(m[s]==1){
        //cout<<s<<" ";
        //cout<<s+" "+y.substr(0,y.size()-1)<<endl;
        string p=s+" "+y.substr(0,y.size()-1);
        if(p[p.size()-1]==' '){
            p=p.substr(0,p.size()-1);
        }
        result.push_back(p);
        //return true;
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
            bool as = recurse(tmp,m,wordDict,word+" "+y,result);
            res = res||as;
        }
    }
    if(!res){
        m[s]=2;
    }
    return  res; 
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> m;
        for(auto x:wordDict){
            m[x]=1;
        }
        vector<string> result;
        recurse(s,m,wordDict,"",result);
        return result;
}

int main(){
	// string s= "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	// vector<string> wordDict={"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	string s="catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    vector<string> result=wordBreak(s,wordDict);
    for(auto x:result){
        cout<<x<<endl;
    }
	return 0;
}


/*
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
*/