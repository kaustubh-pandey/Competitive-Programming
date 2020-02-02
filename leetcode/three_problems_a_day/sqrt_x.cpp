class Solution {
public:
    int bsearch(long long l,long long r,long long x){
       if(l<=r){
        long long mid = (l+r)/2;
       if((long long)mid*mid==x){
           return mid;
       }
       else if((long long)mid*mid<x && (long long)(mid+1)*(mid+1)>x){
           return mid;
       } 
       else if((long long)mid*mid > x){
           return bsearch(l,mid-1,x);
       }
       else{
           return bsearch(mid+1,r,x);
       }    
       } 
       return 0;
    }
    int mySqrt(int x) {
     return bsearch(1,x,x);
    }
};