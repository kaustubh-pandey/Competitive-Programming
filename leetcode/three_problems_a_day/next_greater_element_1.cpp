//Worst case O(n^2) possible
/*class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0 || nums2.size()==0){
            return {};
        }
        map<int,int> m;
        m[nums2[nums2.size()-1]]=-1;
        for(int i=nums2.size()-2;i>=0;i--){
            int curr = nums2[i+1];
            while(curr<=nums2[i]){
                curr = m[curr];
                if(curr==-1){
                    break;
                }
            }
            m[nums2[i]]=curr;
        }
        vector<int> res;
        for(auto x:nums1){
            res.push_back(m[x]);
        }
        return res;
    }
};*
//TODO: O(n) solution using stack