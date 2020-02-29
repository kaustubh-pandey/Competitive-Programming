#include<bits/stdc++.h>
using namespace std;
//Using lower and upper bounds
/*vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>::iterator low = lower_bound(nums.begin(),nums.end(),target);
    vector<int>::iterator high = upper_bound(nums.begin(),nums.end(),target);
    if(low==nums.end() || *low!=target){
        return {-1,-1};
    }
    return {low-nums.begin(),high-nums.begin()-1};
}*/
//Implementing lower bound iterative
class Solution {
public:
    int bsearchLow(vector<int>& nums, int target){
        int first_pos = nums.size();
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>=target){
                first_pos=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return first_pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int  l =bsearchLow(nums,target);
        int  r =bsearchLow(nums,target+1)-1;
        if(l<=r){
            return {l,r};
        }
        return {-1,-1};
    }
};
