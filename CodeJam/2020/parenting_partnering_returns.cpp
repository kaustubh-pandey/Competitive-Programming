#include<bits/stdc++.h>
using namespace std;
bool f(vector<int> a,vector<int> b){
    if(a[1]<=b[0]){
        return false;
    }
    else if(a[0]>=b[1]){
        return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int n,a,b;
        cin>>n;
        vector< vector<int> > v;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            v.push_back({a,b,i});
        }
        sort(v.begin(),v.end());
        char arr[n];
        string res="";
        arr[v[0][2]]='J';
        bool im=true;
        for(int i=1;i<n;i++){
            vector<int> curr = v[i];
            set<char> st;
            for(int j=i-1;j>=0;j--){
                bool flag = f(curr,v[j]);
                if(flag){
                    st.insert(arr[v[j][2]]);
                }
            }
            if(st.size()==2){
                res="IMPOSSIBLE";
                im=false;
                break;
            }
            else if(st.size()==1){
                auto ele = st.begin();
                if(*ele =='C'){
                    arr[v[i][2]]='J';
                }
                else{
                    arr[v[i][2]]='C';
                }
            }
            else{
                arr[v[i][2]]='J';
            }
        }
        if(im){
            for(int i=0;i<n;i++){
                res+=arr[i];
            }
        }
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
}