class Solution {
public:
    bool check(int n){
        int count=0;
        while(n){
            n=n/10;
            count++;
        }
        if(count%2){
            return false;
        }
        return true;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto x:nums){
            if(check(x)){
                count++;
            }
        }
        return count;
    }
};