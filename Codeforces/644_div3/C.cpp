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
		int odd=0;
		int even=0;
		fo(i,n){
			cin>>a[i];
			if(a[i]%2){
				odd++;	
			}
			else{
				even++;	
			}
		}
		if(odd%2==0 && even%2==0){
			cout<<"YES"<<endl;
			continue;	
		}
		sort(a,a+n);
		int visited[n];
		memset(visited,0,sizeof(visited[0])*n);
		Fo(i,1,n){
			if(a[i]-a[i-1]==1 && visited[i]==0 && visited[i-1]==0){
				visited[i]=1;
				visited[i-1]=1;
				if(a[i]%2){odd--;}
				else{even--;}
				if(a[i-1]%2){odd--;}
				else{even--;}	
			}
			if(odd%2==0 && even%2==0){
				break;	
			}	
		}
		if(odd%2==0 && even%2==0){
			cout<<"YES"<<endl;	
		}
		else{
			cout<<"NO"<<endl;	
		}
	}
	return 0;
}
