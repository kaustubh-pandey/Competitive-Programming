#include<bits/stdc++.h>
using namespace std;

//bruteforce O(max(height) * n)
// If n<=10^6 , Won't work well for height[i]>1000
int trap_bruteforce(vector<int>& height) {
    int l=0;
    int r=height.size()-1;
    if(r<0){
        return 0;
    }
    while(l<height.size() && height[l]==0){
        l++;
    }
    while(r>=0 && height[r]==0){
        r--;
    }
    if(l<r-1){
        int ans=0;
        int max_height=0;
        for(auto x:height){
            max_height=max(max_height,x);
        }
        while(max_height--){
            int i=l;
            int total=0;
            while(i<=r){
                //find valley
                int k = i;
                vector<int> decre;
                while(k<r && height[k]>=height[k+1]){
                    decre.push_back(k);
                    k++;
                }
                while(k<r && height[k]<=height[k+1]){
                    decre.push_back(k);
                    k++;
                }
                int level = min(height[k],height[i]);
                for(int g=0;g<decre.size();g++){
                    int quant = (level-height[decre[g]]>0)?level-height[decre[g]]:0;
                    total+=quant;
                    height[decre[g]]+=quant;
                }
                //break;
                if(i==k){
                    i++;
                }
                else{
                    i=k;
                }
            }
            // cout<<total<<endl;
            // for(auto y:height){
            //     cout<<y<<" ";
            // }
            // cout<<endl;
            if(total<=0){
                break;
            }
            
            ans+=total;
        }
        
        return ans;
    }
    return 0;
}
//O(n^2) brute force, worse time complexity than previous method on leetcode testcases
int trap_brute(vector<int>& height) {
        int ans=0; 
        for(int i=0;i<height.size();i++){
            int max_height_l = 0;
            int max_height_r = 0;
            for(int j=i;j>=0;j--){
                max_height_l= max(max_height_l,height[j]);
            }
            for(int j=i;j<height.size();j++){
                max_height_r= max(max_height_r,height[j]);
            }
            ans+= min(max_height_l,max_height_r)-height[i];
        }
        return ans;
}
/*
The above brute force can be optimized by storing max_left and 
max_right for each index. DP solution O(n)
*/
int trapDP(vector<int>& height) {
        int ans=0; 
        vector<int> max_left(height.size());
        vector<int> max_right(height.size());
        int max_l=0;
        int max_r=0;
        for(int i=0;i<height.size();i++){
            max_l = max(max_l,height[i]);
            max_r = max(max_r,height[height.size()-i-1]);
            max_left[i] = max_l;
            max_right[height.size()-i-1] = max_r;
        }
        for(int i=0;i<height.size();i++){
            ans+= min(max_left[i],max_right[i])-height[i];
        }
        return ans;
}
int main(){
	int height[]={5,2,1,2,1,5};
	cout<<trap_bruteforce(height)<<endl;
	return 0;
}