class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if(sum%2){
            return false;
        }
        //check if there is a subset whose sum is equal to target
        //knapsack
        int n = nums.size();
        int W = sum/2;
        bool dp[n+1][W+1];
        for(int i=0;i<=n;i++){
            for(int w=0;w<=W;w++){
                if(i==0){
                    dp[i][w]=false;
                }
                if(w==0){
                    dp[i][w]=true;
                }
                if(i!=0 && w!=0){
                    if(nums[i-1]<=w){
                        dp[i][w] = dp[i-1][w] || dp[i-1][w-nums[i-1]];      
                    }
                    else{
                        dp[i][w]=dp[i-1][w];
                    }
                }
            }
        }
        return dp[n][W];
    }
};