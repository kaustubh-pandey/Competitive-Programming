#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplify(string s){
        string tmp="";
        int flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='@'){
                flag=1;
            }
            if(flag==0 && s[i]=='.'){
                continue;
            }
            else if(flag==0 && s[i]=='+'){
                flag=2;
                continue;
            }
            
            if(flag!=2){
                tmp+=s[i];
            }
        }
        return tmp;
    }
    int numUniqueEmails(vector<string>& emails) {
        set<string> myset;
        for(string s:emails){
            myset.insert(simplify(s));
        }
        return myset.size();
    }
};