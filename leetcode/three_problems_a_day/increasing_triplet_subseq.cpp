#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sec=INT_MAX;
        int trip=INT_MAX;
        int curr = INT_MAX;
        for(auto i : nums){
            if(i<=curr){
                curr=i;
            }
            else if(i<=sec){
                sec=i;
            }
            else{
                return true;
            }
        }
        return false;
    }
};