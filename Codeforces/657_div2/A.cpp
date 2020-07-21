#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a,n) memset(a,0,sizeof(a[0])*n)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
using namespace std;
const int MOD=1000000007;
//const int N=2e5;
//int arr[N+1];

void print() 
{ 
    cout <<endl;
}
template <typename T, typename... Types> 
void print(T var1, Types... var2) 
{ 
    cout << var1 << " " ; 
  
    print(var2...) ; 
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	string st = "abacaba";
	while(t--){
		int n;
		cin>>n;
		string sr;
		cin>>sr;
		int flag2=0;
		//if(sr==st){flag2=1;cout<<"YES"<<endl;cout<<st<<endl;}
		fo(i,n-6){
			string s=sr;
			string sub = s.substr(i,7);
			for(int j=0;j<7;j++){
				if(sub[j]=='?'){
					sub[j]=st[j];
					s[i+j] = st[j];	
				}	
			}
			//cout<<"$"<<sub<<endl;
			if(sub==st){
				int cnt=0;
				fo(k,n-6){
					int flag=0;
					for(int j=k;j<k+7;j++){
						if(s[j]!=st[j-k]){
							flag=1;
							break;	
						}	
					}
					if(!flag){
						cnt++;	
					}	
				}
				if(cnt==1){
					cout<<"YES"<<endl;
					fo(k,n){
						if(s[k]=='?'){s[k]='d';}	
					}
					cout<<s<<endl;	
					flag2=1;
					break;
				}	
			}	
		}
		if(!flag2){
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
}
