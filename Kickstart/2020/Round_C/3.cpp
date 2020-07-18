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
//count number of subarrays with sum prefect square
int P[20000001]; //number of subarrays starting at 0 with this prefix sum
int a[100000];
int main(){
	int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int n;
        cin>>n;
        ll offset = 0;
        ll max_a=0;
        fo(i,n){
        	cin>>a[i];
        	if(a[i]<0){
				offset-=a[i];
			}
			else{
				max_a += a[i];
			}
        }
		memset(P,0,sizeof(P[0])*20000001);
		ll count=0;
		ll prefix_sum=0;
		P[offset]++;
		fo(i,n){
			prefix_sum+=a[i];
			for(int j=0;j*j<=prefix_sum+offset;j++){
				count+= P[prefix_sum-(j*j)+offset];
			}
			P[prefix_sum+offset]++;
		}
        
        cout<<"Case #"<<z<<": "<< count<<endl;
    }
}
