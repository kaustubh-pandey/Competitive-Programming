//dp in O(n^2)
/*class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()){return 0;}
        sort(envelopes.begin(),envelopes.end());
        int n= envelopes.size();
        vector< pair<pair<int,int>,int > > dp(n+1);
        dp[0] = make_pair(make_pair(0,0),1);
        for(int i=1;i<=n;i++){
            int ind=-1;
            int mx=0;
            for(int j=0;j<i;j++){
                if(dp[j].first.first<envelopes[i-1][0] && dp[j].first.second<envelopes[i-1][1]){
                    if(dp[j].second>mx){
                        mx=dp[j].second;
                        ind=j;
                    }
                }
            }
            if(ind!=-1){
               dp[i] = make_pair(make_pair(envelopes[i-1][0],envelopes[i-1][1]),mx+1);    
            }
            
        }
        int maxm = 0;
        for(int i=1;i<=n;i++){
            maxm = max(maxm,dp[i].second);
        }
        return maxm-1;
    }
};*/
// dp in O(nlogn)
