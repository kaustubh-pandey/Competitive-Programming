class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0;
        int r=n-1;
        int res=0;
        while(l<r){
            //cout<<l<<" "<<r<<endl;
            int curr = (r-l)*min(height[l],height[r]);
            res=max(res,curr);
            if(height[l]>height[r]){r--;}
            else{l++;}
        }
        return res;
    }
};