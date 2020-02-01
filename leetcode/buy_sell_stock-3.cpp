#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

bool f(int a,int b,int c){
        if(a==b && b==c){
            return true;
        }
        return false;
}
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if(n==0){
        return 0;
    }
    vector<int> a;
    int mini=prices[0];
    int maxm=0;
    for(int i=1;i<n;i++){
        if(prices[i]<mini){
            mini=prices[i];
        }
        maxm=max(maxm,prices[i]-mini);    
    }
    int valley=0;
    int peak=0;
    int vp=0;
    if(n>2){
       for(int i=0;i<n;i++){
        if(vp==0){
            //find valley
            if(i==0 && prices[1]>=prices[0]){
                valley=0;
                vp=1;
            }
            else if(i==n-1 && prices[n-1]<=prices[n-2]){
                valley=n-1;
                vp=1;
            }
            else if(i>0 && i<n-1 && prices[i]<=prices[i-1] && prices[i]<=prices[i+1] &&!f(prices[i-1],prices[i],prices[i+1])){
                valley=i;
                vp=1;
            }
            
        }
        else if(vp==1){
            //find peak
            if(i==0 && prices[1]<=prices[0]){
                peak=0;vp=0;
            }
            else if(i==n-1 && prices[n-1]>=prices[n-2]){
                peak=n-1;vp=0;
            }
            else if(i>0 && i<n-1 && prices[i]>=prices[i-1] && prices[i]>=prices[i+1] &&!f(prices[i-1],prices[i],prices[i+1])){
                peak=i;vp=0;
            }
            //vp=0;
            
            if(peak>valley){
                cout<<peak<<" "<<valley<<" "<<prices[peak]-prices[valley]<<endl;
                a.push_back(prices[peak]-prices[valley]);    
            }
            
        }
    } 
    }
    cout<<a.size()<<" "<<maxm<<endl;
    if(a.size()<2){
        while(a.size()<2){
            a.push_back(0);
        }
    }
    sort(a.rbegin(),a.rend());
    return max(maxm,a[0]+a[1]);
}

int main(){
    vector<int> prices={7,6,4,3,1};
    cout<<maxProfit(prices)<<endl;
    return 0;
}