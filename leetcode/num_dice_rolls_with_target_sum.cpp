#include<bits/stdc++.h>
using namespace std;

int main(){
	int d,f,target;
	cin>>d>>f>>target;
	    int dp[d][target];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<d;i++){
            for(int j=i;j<target;j++){
                if(i==0 && j<f){
                        dp[i][j]=1;
                }
                else if(i==j){
                    dp[i][j]=1;
                }
                else if(i>0){
                    //take f previous value from above row
                    int sum=0;
                    for(int k=1;k<=f;k++){
                        if(j-k>=0){
                            sum=(sum+dp[i-1][j-k])%((int)1e9+7);
                        }
                    }
                    dp[i][j]=sum%((int)1e9+7);
                }
            }
        }
	return 0;
}