class Solution {
public:
    void generate(vector<vector<int> > &res,vector<int> &nums,unordered_map<int,bool>&m,vector<int> &tmp){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!m[nums[i]]){
                m[nums[i]]=true;
                tmp.push_back(nums[i]);
                generate(res,nums,m,tmp);
                m[nums[i]]=false;
                tmp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        unordered_map<int,bool>m;
        vector<int> tmp;
        generate(res,nums,m,tmp);
        return res;
    }
};