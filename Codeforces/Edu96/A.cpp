#include<bits/stdc++.h>
#define ll long long
#define xll __int128
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
#define TIK auto start = chrono::high_resolution_clock::now();
#define TOK auto end = chrono::high_resolution_clock::now();double time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count();time_taken *= 1e-9;cerr << "Time taken:" << fixed << time_taken << setprecision(9);cerr << " sec" << endl;
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
	TIK
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%3==0){
			cout<< n/3 <<" ";
			cout<<0<<" ";
			cout<<0<<endl;
		}
		else if(n%5==0){
			cout<<0<<" ";
			cout<<n/5<<" ";
			cout<<0<<endl;
		}
		else if(n%7==0){
			cout<<0<<" ";
			cout<<0<<" ";
			cout<<n/7<<endl;
		}
		else{
			unordered_map<int,int> m;
			fo(i,n){
				m[n-(3*i)] =1;
			}
			int flag=0;
			fo(j,n){
				fo(k,n){
					if(m[5*j + 7*k]==1){
						cout<< (n-(5*j+7*k))/3 <<" ";
						cout<<j<<" ";
						cout<<k<<endl;
						flag=1;
						break;
					}
				}
				if(flag==1){
					break;
				}
			}
			if(flag){
				continue;
			}
			else{
				cout<<-1<<endl;
			}
		}			
	}
	
	TOK
	return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!*/
