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
		int a[n];
		int b[n];
		fo(i,n){
			cin>>a[i];
		}
		fo(i,n){
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		int s=0;
		int e=n-1;
		while(k--){
			if(a[s]<b[e]){
				//swap
				int tmp = a[s];
				a[s]=b[e];
				b[e]=tmp;
				s++;e--;
			}
			else{
				break;
			}
		}
		ll sum=0;
		fo(i,n){
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}