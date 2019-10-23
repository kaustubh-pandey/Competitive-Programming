#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int32_t main()
{
	
	int t;
	cin>>t;
	while(t--){
		int n,temp;
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>temp;
			sum+=temp;
		}
		cout<<(sum+n-1)/n<<endl;
	}
	

	return 0;
}