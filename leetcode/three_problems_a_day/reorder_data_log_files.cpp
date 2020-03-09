class Solution {
public:
    bool isDigit(string s){
        int i=0;
        while(s[i]!=' '){
            i++;
        }
        i++;
        if((s[i]>=97 && s[i]<(97+26)) || (s[i]>=65 && s[i]<(65+26))){
            return false;
        }
        return true;
    }
    pair<string,string> split(string s){
        int i=0;
        string key="";
        while(s[i]!=' '){
            key+=s[i];
            i++;
        }
        i++;
        string val="";
        while(i<s.size()){
            val+=s[i];
            i++;
        }
        return make_pair(val,key);
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector< pair<string,string> > letLog;
        vector<string> digitLog;
        for(auto x:logs){
            if(isDigit(x)){
                digitLog.push_back(x);
            }
            else{
                letLog.push_back(split(x));
            }
        }
        sort(letLog.begin(),letLog.end());
        vector<string> res;
        for(auto x:letLog){
            res.push_back(x.second+" "+x.first);
        }
        for(auto x:digitLog){
            res.push_back(x);
        }
        return res;
    }
};