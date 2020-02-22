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
	string s;
	cin>>s;
	int n=s.size();
	//d 1,n-1
	map<string,int> m;
	int maxm = INT_MIN;
	for(int i=0;i<n;i++){
		m[s[i]+""]++;
	}
	for(int d=1;d<n;d++){
		for(int i=0;i<d;i++){
			string q="";
			for(int j=i;j<n;j+=d){
				q+=s[j];
				m[q]+=1;
			}
		}
	}
	for(auto x:m){
		maxm = max(x.second,maxm);
	}
	cout<<maxm<<endl;
	return 0;
}