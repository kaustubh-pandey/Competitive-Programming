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
int inc(int val){
	if(val==9){
		return 1;	
	}
	return val+1;	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a[9][9];
		fo(i,9){
			string s;
			cin>>s;
			for(int j=0;j<9;j++){
				a[i][j] = s[j]-'0';	
			}	
		}
		a[0][0] = inc(a[0][0]);
		a[1][3] = inc(a[1][3]);
		a[2][6] = inc(a[2][6]);
		a[3][1] = inc(a[3][1]);
		a[4][4] = inc(a[4][4]);
		a[5][7] = inc(a[5][7]);
		a[6][2] = inc(a[6][2]);
		a[7][5] = inc(a[7][5]);
		a[8][8] = inc(a[8][8]);
		
		fo(i,9){
			for(int j=0;j<9;j++){
				cout<<a[i][j];	
			}
			cout<<endl;	
		}	
	}
	return 0;
}
