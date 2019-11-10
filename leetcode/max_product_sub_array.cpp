#include<bits/stdc++.h>
using namespace std;
int max_product_subarray(vector<int>&nums){
 	int n=nums.size();
    int max_so_far=nums[0];
    int max_ending_here=nums[0];
    int max_prev=nums[0];
    int min_ending_here=nums[0];
    for(int i=1;i<n;i++){
        max_prev=max_ending_here;
        max_ending_here = max(max(max_ending_here*nums[i],nums[i]),min_ending_here*nums[i]);
        min_ending_here = min(min(min_ending_here*nums[i],nums[i]),max_prev*nums[i]); //max_prev used as max_end_here is getting changed in the above step
        max_so_far = max(max_so_far,max_ending_here);
    }
    return max_so_far;
}
int main(){
	int n;
	cin>>n;
	vector<int> nums(0,n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<<max_product_subarray(nums)<<endl;
	return 0;
}