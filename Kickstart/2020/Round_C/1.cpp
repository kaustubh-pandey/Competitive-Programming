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
        int n,k;
        cin>>n>>k;
        int a[n];
        fo(i,n){
        	cin>>a[i];
        }
        int count=0;
        fo(i,n){
        	if(a[i]==k){
        		//cout<<i<<endl;
        		int index = i;
        		int kc = k;
        		int flag = 1;
        		while(index<n && kc>0){
					if(a[index]!=kc){
						flag=0;
						break;
					}
					//cout<<index<<" "<<a[index]<<" "<<kc<<" "<<flag<<endl;
					kc--;
					index++;
				}
				//cout<<flag<<" "<<count<<endl;
				 if(flag && kc==0){
				 	count++;
				 	i = index-1;
				 }
				 //cout<<count<<endl;
        	}
        }
        cout<<"Case #"<<z<<": "<<count <<endl;
    }
}
