class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,bool> m;
        for(auto x:J){
            m[x]=true;
        }
        int count=0;
        for(auto x:S){
            if(m[x]){
                count++;
            }
        }
        return count;
    }
};