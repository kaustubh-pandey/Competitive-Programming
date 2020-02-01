#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std

int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
	int dp[books.size()];
	for(int i=0;i<books.size();i++){
		int width = books[i][0];
		int height = books[i][1];
		dp[i] = ((i>0)?dp[i-1]:0 )+height;
		cout<<dp[i]<<endl;
		for(int j=i-1;j>=0 && width+books[j][0]<=shelf_width;j--){
			width += books[j][0];
			height = max(height,books[j][1]);
			dp[i] = min(dp[i],((j>0)?dp[j-1]:0)+height);
			cout<<dp[i]<<endl;
		}
	}
	return dp[books.size()-1];
}
int minHeightShelves2(vector<vector<int>>& books, int shelf_width) {
	int dp[books.size()+1];
	dp[0]=0;
	for(int i=1;i<=books.size();i++){
		int width = books[i-1][0];
		int height = books[i-1][1];
		dp[i] = dp[i-1]+height;
		cout<<dp[i]<<endl;
		for(int j=i-1;j>0 && width+books[j-1][0]<=shelf_width;j--){
			width += books[j-1][0];
			height = max(height,books[j-1][1]);
			dp[i] = min(dp[i],dp[j-1]+height);
			cout<<dp[i]<<endl;
		}
	}
	return dp[books.size()];
}
int main(){
	vector<vector<int> > books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
	minHeightShelves(books,4);
	cout<<"###############################################"<<endl;
	minHeightShelves2(books,4);
	return 0;
}
