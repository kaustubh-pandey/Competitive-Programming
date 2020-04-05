#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int n,b;
        cin>>n>>b;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int val=0;
        int count=0;
        for(auto x:a){
            if(val+x<=b){
                val+=x;
                count++;
            }
        }
        cout<<"Case #"<<z<<": "<<count<<endl;
    }
}