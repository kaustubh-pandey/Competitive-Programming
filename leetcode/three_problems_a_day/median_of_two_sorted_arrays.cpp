class Solution {
public:
    double f(vector<int> nums1,vector<int> nums2){
        int n = nums1.size(); //X
        int m = nums2.size();   //Y
        //Doing binary search on nums1
        int low = 0;
        int high = n;
        
        while(low<=high){
            int partX = (low+high)/2;
            int partY = (m+n+1)/2 -  partX;
            int maxLeftX = (partX == 0) ? INT_MIN : nums1[partX - 1];
            int minRightX = (partX == n) ? INT_MAX : nums1[partX];

            int maxLeftY = (partY == 0) ? INT_MIN : nums2[partY - 1];
            int minRightY = (partY == m) ? INT_MAX : nums2[partY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                if((n+m)%2==0){
                    return (double)(max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2;
                }
                return (double)max(maxLeftX,maxLeftY);
            }
            else if(maxLeftX > minRightY){
                high = partX-1;
            }
            else{
                low = partX + 1;
            }
            
        }
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); //X
        int m = nums2.size();   //Y
        if(n==0 && m==0){
            return 0.0;
        }
        else if(n>m){
            return f(nums2,nums1);
        }
        return f(nums1,nums2);
        
    }
};