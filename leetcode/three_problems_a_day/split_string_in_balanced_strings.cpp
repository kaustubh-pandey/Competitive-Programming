class Solution {
public:
    int balancedStringSplit(string s) {
        int r=0;
        int l=0;
        int count=0;
        for(auto x:s){
            if(x=='R'){
                r++;
            }
            else{
                l++;
            }
            if(r==l){
                count++;
                r=0;l=0;
            }
        }
        return count;
    }
};