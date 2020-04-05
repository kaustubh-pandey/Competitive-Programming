#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
#define mp make_pair
#define F first
#define S second
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int n;
        cin>>n;
        int mat[101][101];
        memset(mat,0,sizeof(mat));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }
        int r=0,c=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> m;
            for(int j=0;j<n;j++){
                m[mat[i][j]]++;
            }
            for(auto x:m){
                if(x.second!=1){
                    r++;
                    break;
                }
            }
        }
        for(int j=0;j<n;j++){
            unordered_map<int,int> m;
            for(int i=0;i<n;i++){
                m[mat[i][j]]++;
            }
            for(auto x:m){
                //cout<<x.first<<" "<<x.second<<endl;
                if(x.second!=1){
                    c++;
                    break;
                }
            }
        }
        int diag=0;
        for(int i=0,j=0;i<n && j<n;i++,j++){
            diag+=mat[i][j];
        }
        cout<<"Case #"<<z<<": "<<diag<<" "<<r<<" "<<c<<endl;
    }
    return 0;
}