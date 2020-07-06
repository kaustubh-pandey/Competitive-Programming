class Solution {
public:
    int calcScore(string s,vector<int> score){
        int res=0;
        for(int i=0;i<s.size();i++){
            res+= score[s[i]-'a'];
        }
        return res;
    }
    bool freqCheck(string s,map<char,int> m){
        map<char,int> tmp;
        for(int i=0;i<s.size();i++){
            tmp[s[i]]++;
        }
        for(auto x:tmp){
            if(x.second>m[x.first]){
                return false;
            }
        }
        return true;
    }
    map<char,int> subtract(map<char,int> m,string s){
        map<char,int> tmp;
        for(int i=0;i<s.size();i++){
            tmp[s[i]]++;
        }
        for(auto x:m){
            tmp[x.first] = x.second - tmp[x.first];
        }
        return tmp;
    }
    bool isZero(map<char,int> m){
        for(auto x:m){
            if(x.second>0){
                return false;
            }
        }
        return true;
    }
    int knapsack(vector< pair<string,int>  > score_list,map<char,int> m,int n,map<int, map< map<char,int> ,int> > &dp){
        if(n==0 || isZero(m)){
            return 0;
        }
        if(dp[n][m]){
            return dp[n][m];
        }
        if(freqCheck(score_list[n-1].first,m)){
            return dp[n][m] = max(score_list[n-1].second+knapsack(score_list,subtract(m,score_list[n-1].first),n-1,dp),knapsack(score_list,m,n-1,dp));
        }
       
        return dp[n][m]=knapsack(score_list,m,n-1,dp);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int> m;
        for(auto x:letters){
            m[x]++;
        }
        vector< pair<string,int>  > score_list;
        for(auto x:words){
            score_list.push_back(make_pair(x,calcScore(x,score)));
        }
        int n = words.size();
        map<int, map< map<char,int> ,int> > dp;
        return knapsack(score_list,m,n,dp);   
    }
};