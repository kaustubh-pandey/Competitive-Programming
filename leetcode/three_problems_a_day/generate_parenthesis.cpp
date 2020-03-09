class Solution {
public:
    void generate(string s,int n,int open,int close,vector<string> &res){
        if(open==n && close==n){
            res.push_back(s);
            return;
        }
        if(open<n){
            generate(s+"(",n,open+1,close,res);
        }
        if(open > close && close<n){
            generate(s+")",n,open,close+1,res);
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n==0){
            return {""};
        }
        vector<string> res;
        generate("(",n,1,0,res);
        return res;
    }
};