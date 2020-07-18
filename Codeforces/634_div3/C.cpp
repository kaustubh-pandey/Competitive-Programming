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
		fo(i,n){
			cin>>a[i];	
		}
		map<int,int> freq;
		set<int> uni;
		fo(i,n){
			freq[a[i]]++;
			uni.insert(a[i]);	
		}
		int max_freq=0;
		for(auto x:freq){
			max_freq = max(max_freq,x.second);	
		}
		if(max_freq<=1){
			if(n>1){
				cout<<1<<endl;	
			}
			else{
				cout<<0<<endl;	
			}
		}
		else{
			int same = max_freq;
			if((int)uni.size()==same){
				cout<<same-1<<endl;	
			}
			else{
				cout<< min((int)uni.size(),same)<<endl;		
			}
		}
	}
	return 0;
}
