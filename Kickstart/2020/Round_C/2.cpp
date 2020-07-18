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
void print(char mat[][30]){
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int r,c;
        cin>>r>>c;
        char mat[30][30];
        for(int i=0;i<r;i++){
        	for(int j=0;j<c;j++){
        		cin>>mat[i][j];
        	}
        }
        //print(mat);
        bool flag  = false;
        vector<char> vals;
        map<char,bool> done;
        map<char,bool> prev;
        for(int j=0;j<c;j++){
        	map<char,bool> m;
        	for(int i=r-1;i>=0;i--){
        		char tmp = mat[i][j];
        		if(m[tmp] || (done[tmp] && i<r-1 && !done[mat[i+1][j]]) || (j>0 && tmp!=mat[i][j-1] && done[tmp] && !prev[tmp])){
        			//cout<<done[tmp]<<" "<<i<<" "<<j<<" "<<mat[i+1][j]<<tmp<<endl;
        			flag=true;
        			break;
        		}
        		m[tmp]=true;
        		int index = i;
        		while(index>=0 && mat[index][j]==tmp){
        			index--;
        		}
        		i = index+1;
        	}
        	if(flag){
        		break;
        	}
        	prev=m;
        	for(auto x:m){
        		if(x.second && !done[x.first]){
        			vals.push_back(x.first);
        			//cout<<x.first<<endl;
        			done[x.first]=true;
        		}
        	}
        }
        bool flag2  = false;
        vector<char> vals2;
        map<char,bool> done2;
        map<char,bool> prev2;
        if(flag){
        	for(int j=c-1;j>=0;j--){
        	map<char,bool> m;
        	for(int i=r-1;i>=0;i--){
        		char tmp = mat[i][j];
        		if(m[tmp] || 
        		(done2[tmp] && i<r-1 && !done2[mat[i+1][j]]) ||
        		 (j<c-1 && tmp!=mat[i][j+1] && done2[tmp] && !prev2[tmp])){
        			//cout<<done[tmp]<<" "<<i<<" "<<j<<" "<<mat[i+1][j]<<tmp<<endl;
        			flag2=true;
        			break;
        		}
        		m[tmp]=true;
        		int index = i;
        		while(index>=0 && mat[index][j]==tmp){
        			index--;
        		}
        		i = index+1;
        	}
        	if(flag2){
        		break;
        	}
        	prev2=m;
        	for(auto x:m){
        		if(x.second && !done2[x.first]){
        			vals2.push_back(x.first);
        			//cout<<x.first<<endl;
        			done2[x.first]=true;
        		}
        	}
        }
        }
        string res="";
        if(flag && flag2){
        	res="-1";
        }
        else if(!flag){
        	for(auto x:vals){
        		res+=x;
        	}
        }
        else if(!flag2){
        	for(auto x:vals2){
        		res+=x;
        	}
        }
        cout<<"Case #"<<z<<": "<<res <<endl;
    }
}
