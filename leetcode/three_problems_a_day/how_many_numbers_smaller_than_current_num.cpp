class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> nums_copy;
        for(auto x:nums){
            nums_copy.push_back(x);
        }
        sort(nums_copy.begin(),nums_copy.end());
        unordered_map<int,int> m;
        int count=0;
        for(int i=0;i<nums_copy.size();i++){
            if(m.find(nums_copy[i])==m.end()){
                m[nums_copy[i]]=count;   
            }
            count++;
        }
        vector<int> res;
        for(auto x:nums){
            res.push_back(m[x]);
        }
        return res;
    }
};