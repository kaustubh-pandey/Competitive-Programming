class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1){
            return 0;
        }
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid==0){
                if(nums[mid]>=nums[mid+1]){
                    return mid;
                }
                else{
                    low = mid+1;
                    continue;
                }
            }
            else if(mid==n-1){
                if(nums[mid]>=nums[mid-1]){
                 return mid;   
                }
                else{
                    high = mid-1;
                    continue;
                }
            }
            
            if(nums[mid]>=nums[mid-1] && nums[mid]>=nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>=nums[mid-1] && nums[mid]<=nums[mid+1]){
                low = mid+1;
            }
            else if(nums[mid]<=nums[mid-1] && nums[mid]>=nums[mid+1]){
                high = mid-1;
            }
            else{
                if(high>0){
                    high--;
                }
                else if(low<n-1){
                    low++;
                }
            }
            
        }
        return 0;
    }
};