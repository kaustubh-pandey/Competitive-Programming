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
#define endl "\n"
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
using namespace std;
const int MOD=1000000007;

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
//ceil of a/b
template <typename T>
T fceil(T a,T b){
    return (T)(a+b-1)/b;			
}
//const int N=2e5;
//int arr[N+1];
ll gen(int a,int b,int c,int d,int k1,int k2){
	ll val = (a*k2)%d;
	val = (val + ((ll)b*k1)%d)%d;
	val = (val+c)%d;
	return val+1;	
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	for(int z=0;z<t;z++){
		int n,k,w;
		cin>>n>>k>>w;
		vector<ll> L(k,0);
		vector<ll> H(k,0);
		fo(i,k){
			cin>>L[i];	
		}
		int al,bl,cl,dl;
		cin>>al>>bl>>cl>>dl;
		Fo(i,k,n){
			L.pb(gen(al,bl,cl,dl,L[i-1],L[i-2]));	
		}
		fo(i,k){
			cin>>H[i];	
		}
		int ah,bh,ch,dh;
		cin>>ah>>bh>>ch>>dh;
		Fo(i,k,n){
			H.pb(gen(ah,bh,ch,dh,H[i-1],H[i-2]));	
		}
		
		ll P=(ll)(2*w+2*H[0]);
		ll pro=1;
		Fo(i,1,n){
			print(P);
			pro = (pro * P)%MOD;
			if(L[i]<=L[i-1]+w){
				P = (((P + (H[i] - H[i-1]))%MOD + abs(H[i]-H[i-1]))%MOD + (2*(L[i]-L[i-1]))%MOD)%MOD;	
			}
			else{
				P = ((P + (2*w)%MOD)%MOD + (2*H[i])%MOD)%MOD;
			}
		}
		print(P);
		pro = (pro * P)%MOD;
		cout<<"Case #"<<z+1<<": "<<pro<<endl;				
	}
	return 0;
}
