#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a) memset(a,0,sizeof(a))
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int> a(n,0);
		fo(i,n){
			cin>>a[i];
		}
		int sum=0;
		Fo(i,1,n){	
			if(d<=0){
				break;
			}
			int moveable = min((int)d/i,a[i]);
			sum+=moveable;
			d=d-(moveable*i);
		}
		cout<<a[0]+sum<<endl;
	}
	return 0;
}