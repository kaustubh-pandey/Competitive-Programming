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
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	fo(z,t){
		int n;
		cin>>n;
		char mat[51][51];
		string inb;
		string outb;
		cin>>inb;
		cin>>outb;
		fo(i,n){
			mat[i][i]='Y';	
		}
		int i=0,j=1;
		while(j<n){
			mat[i][j]= (outb[i]=='Y' && inb[j]=='Y')?'Y':'N';
			i++;j++;	
		}
		i=1;j=0;
		while(i<n){
			mat[i][j]= (outb[i]=='Y' && inb[j]=='Y')?'Y':'N';
			i++;j++;	
		}
		for(i=0;i<n;i++){
			for(j=i+2;j<n;j++){
				mat[i][j] = (mat[i][j-1]=='Y' && mat[j-1][j]=='Y')?'Y':'N';	
			}	
		}
		for(i=2;i<n;i++){
			for(j=i-2;j>=0;j--){
				mat[i][j] = (mat[i][j+1]=='Y' && mat[j+1][j]=='Y')?'Y':'N';	
			}	
		}
		cout<<"Case #"<<z+1<<":"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<mat[i][j];	
			}
			cout<<endl;	
		}		
	}
	return 0;
}
