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
	int n;
	cin>>n;
	int a[n];
	fo(i,n){
		cin>>a[i];
	}
	Fo(i,1,n-1){
		if(a[i-1]>a[i] && a[i]<a[i+1]){
			if(a[i-1]<a[i+1]){
				a[i-1]=a[i];
			}
			else{
				a[i+1]=a[i];
			}
		}
	}
	fo(i,n){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}