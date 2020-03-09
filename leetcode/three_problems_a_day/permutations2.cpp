class Solution {
public:
    void generate(vector<vector<int> > &res,vector<int> &nums,unordered_map<int,bool>&m,vector<int> &tmp){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!m[i]){
                if(i>0 && nums[i]==nums[i-1] && m[i-1]){
                    return;
                }
                m[i]=true;
                tmp.push_back(nums[i]);
                generate(res,nums,m,tmp);
                m[i]=false;
                tmp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,bool>m;
        vector<int> tmp;
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        generate(res,nums,m,tmp);
        return res;  
    }
};