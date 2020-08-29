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
#define Endl "\n"
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
using namespace std;
const int MOD=1000000007;
void print(){cout <<endl;}
template <typename T, typename... Types> 
void print(T var1, Types... var2){cout << var1 << " " ;print(var2...) ;}
//ceil of a/b
template <typename T>
T fceil(T a,T b){return (T)(a+b-1)/b;}
template <typename T>
void printvec(vector<T> v){ for(int i=0;i<(int)v.size();i++){ cout<<v[i]<<" ";} cout<<endl;}
template <typename T>
void printarr(T a[],int n){ for(int i=0;i<n;i++){ cout<<a[i]<<" ";} cout<<endl;}
//const int N=2e5;
//int arr[N+1];

 
int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	fo(i,n){cin>>a[i];}
	map<int,bool> m;
	int flag=1;
	fo(i,n){
		int num=a[i];
		if(num%2==0){
			if(m[2]){flag=0;break;}
			m[2]=true;
			while(num%2==0){
				num=num/2;	
			}	
		}
		for(int k=3;k*k<=a[i];k+=2){
			if(num%k==0){
				if(m[k]){flag=0;break;}
				m[k]=true;
				while(num%k==0){
					num=num/k;	
				}	
			}	
		}
		if(m[num]){flag=0;break;}
		m[num]=true;
		if(flag==0){break;}	
	}
	int gc=a[0];
	Fo(i,1,n){
		gc = __gcd(gc,a[i]);	
	}
	if(flag){
		cout<<"pairwise coprime"<<endl;	
	}
	else if(gc==1){
		cout<<"setwise coprime"<<endl;	
	}
	else{
		cout<<"not coprime"<<endl;	
	}
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
