#include<bits/stdc++.h>
#define ll long long

using namespace std;
void precompute(int lps[],string pattern){
	int m = pattern.size();
	lps[0]=0;
	int i=1;
	int j=0;
	while(i<m){
		if(pattern[i]==pattern[j]){
			lps[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j==0){
				lps[i]=0;
				i++;
			}
			else{
				j=lps[j-1];
			}
		}
	}
}
int main(){
	string pattern = "aabcdaabaabaa";
	int lps[pattern.size()];
	precompute(lps,pattern);
	for(int i=0;i<pattern.size();i++){
		cout<<lps[i]<<" \n"[i==pattern.size()-1];
	}
	return 0;
}