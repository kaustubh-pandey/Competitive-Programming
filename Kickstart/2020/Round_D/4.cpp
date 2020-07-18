#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a,n) memset(a,0,sizeof(a[0])*n)
#define mp make_pair
#define F first
#define S second
using namespace std;
const int MOD=1000000007;
//const int N=2e5;
//int arr[N+1];
int solve(vector<int> d,int n,int s,int k){
	s--;
	int left = s-1;
	int right = s;
	int count=1;
	while(left>=0 && right<n-1){
		//cout<<left<<" "<<right<<" "<<s<<endl;
		if(count==k){
			return s+1;	
		}
		if(d[left]<d[right]){
			left--;
			s=left+1;
			count++;	
		}
		else{
			right++;
			s=right;
			count++;
		}	
	}
	while(left>=0){
		if(count==k){
			return s+1;	
		}
		left--;
		s=left+1;
		count++;	
	}
	while(right<n-1){
		if(count==k){
			return s+1;	
		}
		right++;
		s=right;
		count++;	
	}
	if(count==k){
			return s+1;	
	}
	return -1;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
        int n,q;
        cin>>n>>q;
        vector<int> d(n-1,0);
        fo(i,n-1){
			cin>>d[i];	
		}
		vector<int> res;
		while(q--){
			int s,k;
			cin>>s>>k;
			res.push_back(solve(d,n,s,k));	
		}
        cout<<"Case #"<<z<<": ";
        for(int i=0;i<(int)res.size();i++){
			cout<<res[i]<<" ";	
		}
		cout<<endl;
    }
	return 0;
}
