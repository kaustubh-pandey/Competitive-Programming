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
		int n,k;
		cin>>n>>k;
		if(n%2 && k%2==0){
			cout<<"NO"<<endl;
		}
		else{
			if(n%2){
				if(k%2){
					int val = n/k;
					if(val%2==0){
						val++;
					}
					ll last = (ll)n-(ll)((ll)val*(ll)(n-1));
					if(last!=0 && last%2==val%2){
						cout<<"YES"<<endl;
						for(int k=0;k<n-1;k++){
							cout<<val<<" ";
						}
						cout<<last<<endl;
					}
					else{
						cout<<"NO"<<endl;
					}
				}
				else{
					cout<<"NO"<<endl;
				}
			}
			else{
				int val = n/k;
				if(k%2){
					if(val%2){
						val++;
					}
					ll last = (ll)n-(ll)((ll)val*(ll)(n-1));
					if(last!=0 && last%2==val%2){
						cout<<"YES"<<endl;
						for(int k=0;k<n-1;k++){
							cout<<val<<" ";
						}
						cout<<last<<endl;
					}
					else{
						cout<<"NO"<<endl;
					}
					
				}
				else{
					ll last = (ll)n-(ll)((ll)val*(ll)(n-1));
					if(last!=0 && last%2==val%2){
						cout<<"YES"<<endl;
						for(int k=0;k<n-1;k++){
							cout<<val<<" ";
						}
						cout<<last<<endl;
					}
					else{
						cout<<"NO"<<endl;
					}
				}
			}
		}
	}
	return 0;
}