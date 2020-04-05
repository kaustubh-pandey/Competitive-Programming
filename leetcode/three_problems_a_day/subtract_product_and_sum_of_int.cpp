class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro =1;
        int sum=0;
        while(n){
            int digit = n%10;
            n/=10;
            pro*=digit;
            sum+=digit;
        }
        return pro-sum;
    }
};