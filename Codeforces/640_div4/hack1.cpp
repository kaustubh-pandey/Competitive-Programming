#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int num=0,k,n1=0,n;
        cin>>n>>k;
        n1=n-1;
        n1=k/n1;
        num=(n1*n);
        n1=n1*(n-1);
        
        while(n1<k)
        {
            num=num+n;
            n1=n1+n-1;
        }
        cout<<(num-(n1-k)-1)<<"\n";
        
    }
    return 0;
}