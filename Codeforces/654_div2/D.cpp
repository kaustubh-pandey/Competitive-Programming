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
ll max(ll a,ll b){
	if(a>b){return a;}
	return b;	
}
ll min(ll a,ll b){
	if(a<b){return a;}
	return b;	
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		//cout<<t<<endl;
		int n,k;
		cin>>n>>k;
		//cout<<"kahs"<<endl;
		int mat[300][300] = {0};
		int row[300]= {0};
		int col[300] = {0};
		int i=0,j=0;
		int cnt=0;
		while(k>0){
			mat[i][j]=1;
			row[i]++;
			col[j]++;
			k--;cnt++;
			i++;j++;
			if(i==n){
				i=0;	
			}
			if(j==n){
				j=0;
			}
			if(cnt==n){
				cnt=0;
				j++;	
			}
		}
		ll rowMin=INT_MAX,rowMax=0,colMin=INT_MAX,colMax=0;
		fo(l,n){
			rowMin = min(rowMin,row[l]);
			rowMax = max(rowMax,row[l]);
			colMin = min(colMin,col[l]);
			colMax = max(colMax,col[l]);	
		}
		cout<< (rowMax-rowMin)*(rowMax-rowMin) + (colMax-colMin)*(colMax-colMin) << endl;
		fo(l,n){
			fo(r,n){
				cout<<mat[l][r];
			}
			cout<<"\n";	
		}
	}
	return 0;
}
