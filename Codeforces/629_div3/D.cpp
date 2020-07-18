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
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int val;
		cin>>a[0];
		val = a[0];
		bool flag=  true;
		Fo(i,1,n){
			cin>>a[i];
			if(flag && a[i]!=val){
				flag=false;	
			}
		}
		if(flag){
			cout<<1<<endl;
			fo(i,n){
				cout<<1<<" ";	
			}
			cout<<endl;	
		}
		else if(n%2){
			int index=-1;
			Fo(i,1,n){
				if(a[i]==a[i-1]){
					index=i;
					break;	
				}	
			}
			if(index!=-1){
				cout<<2<<endl;
				fo(i,index){
					cout<< (i%2)+1 <<" ";	
				}
				Fo(i,index,n){
					cout<< 2-(i%2) <<" ";
				}
				cout<<endl;
			}
			else{
				if(a[0]==a[n-1]){
					cout<<2<<endl;
					fo(i,n){
						cout<< (i%2)+1<<" ";	
					}	
					cout<<endl;
				}
				else{
					cout<<3<<endl;
					fo(i,n-1){
						cout<< (i%2)+1 <<" ";	
					}
					cout<<3<<endl;	
				}	
			}
		}
		else{
			cout<<2<<endl;
			fo(i,n){
				cout<< (i%2)+1 <<" ";	
			}
			cout<<endl;	
		}
	}
	return 0;
}
