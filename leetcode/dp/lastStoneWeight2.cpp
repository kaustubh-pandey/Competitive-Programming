class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n =stones.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return stones[0];
        }
        int S=0;
        for(auto x:stones){
            S+=x;
        }
        bool dp[n+1][S+1];
        memset(dp,false,sizeof(dp));
        for(int j=0;j<=S;j++){
            dp[0][j]=false;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=S;j++){
                if(stones[i-1]<=j){
                    dp[i][j] = dp[i-1][j-stones[i-1]] || dp[i-1][j];    
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int minm = INT_MAX;
        for(int j=S/2;j<=S;j++){
            if(dp[n][j] && (2*j>=S)){
                minm = min(minm,2*j-S);
            }
        }
        return minm;
    }
};