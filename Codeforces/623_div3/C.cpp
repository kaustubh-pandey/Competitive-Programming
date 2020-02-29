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
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		int a[m];
		fo(i,m){
			cin>>a[i];
		}
		map<int,map<char,int> > my;
		map<char,int> tmp;
		fo(i,n){
			if(i>0){
				tmp = my[i-1];
				tmp[s[i]]++;
				my[i]=tmp;
			}
			else{
				tmp[s[0]]++;
				my[0]=tmp;
			}
		}
		// for(auto x:my){
		// 	for(auto y:x.second){
		// 		cout<<y.first<<" "<<y.second<<endl;
		// 	}
		// 	cout<<endl;
		// }
		int freq[26];
		zero(freq);
		fo(i,m){
			tmp = my[a[i]-1];
			for(auto x:tmp){
				freq[x.first-'a']+=x.second;
			}
		}
		fo(i,n){
			freq[s[i]-'a']++;
		}
		fo(i,26){
			cout<<freq[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}