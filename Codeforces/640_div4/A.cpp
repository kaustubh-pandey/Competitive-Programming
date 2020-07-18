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
		int count=0;
		if(n==0){
			cout<<0;
		}
		vector<int> res;
		while(n){
			int rem= n%10;
			n=n/10;
			if(rem!=0){
				res.push_back(rem*pow(10,count));
			}
			count++;
		}
		cout<<res.size()<<endl;
		for(auto x:res){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}