#include <bits/stdc++.h>
#define N 1000000
using namespace std;
int num(int n,int x){
    if(n%x){
        return n/x;
    }
    return n/x-1;
}
vector<int> indexOfsetbits(int n,int size){
    vector<int> index;
    int count=0;
    while(n){
        if(n&1){
            index.push_back(size-count-1);
        }
        n=n>>1;
        count++;
    }
    return index;
}
int main() {
	//code
	bool seive[N+1];
	memset(seive,true,sizeof(seive));
	for(int i=2;i*i<=N;i++){
	    if(seive[i]){
	        for(int j=i*i;j<=N;j+=i){
	            seive[j]=false;
	        }
	    }
	}
	vector<int> prime;
	for(int i=2;i<=N;i++){
	    if(seive[i]){
	        prime.push_back(i);
	    }
	}
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int m=n;
	    vector<int> factors;
	    for(int i=0;i<prime.size();i++){
	        if(n%prime[i]==0){
	            factors.push_back(prime[i]);
	            while(n%prime[i]==0){
	                n=n/prime[i];
	            }
	            if(seive[n] && n!=1){
	                factors.push_back(n);
	                break;
	            }
	        }
	    }

	   // for(int i=0;i<factors.size();i++){
	   //     cout<<factors[i]<<" ";
	   // }
	   // cout<<endl;
	    int res=0;
	    for(int i=1;i<=(1<<factors.size())-1;i++){
	        vector<int> index = indexOfsetbits(i,factors.size());
	       // for(int k=0;k<index.size();k++){
	       //     cout<<index[k]<<"#";
	       // }
	       // cout<<endl;
	        int pro=1;
	        for(int j=0;j<index.size();j++){
	            pro = pro * factors[index[j]];
	        }
	        int term = num(m,pro);
	        if(index.size()%2){
	            res+=term;
	        }
	        else{
	            res-=term;
	        }
	    }
	    cout<<res+1<<endl;
	    
	}
	return 0;
}