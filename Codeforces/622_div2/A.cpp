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
		int a,b,c;
		cin>>a>>b>>c;
		int count =0;
		if(a>0){
			count++;
			a--;
		}
		if(b>0){
			count++;
			b--;
		}
		if(c>0){
			count++;
			c--;
		}
		vector<int> tmp ={a,b,c};
		sort(tmp.rbegin(),tmp.rend());
		a=tmp[0];
		b=tmp[1];
		c=tmp[2];
		if(tmp[0]>0 && tmp[1]>0){
			count++;
			a--;b--;
		}
		if(b>0 && c>0){
			count++;
			b--;c--;
		}
		if(a>0 && c>0){
			count++;
			a--;c--;
		}
		if(a>0 && b>0 && c>0){
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}