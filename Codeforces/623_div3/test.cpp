#include<bits/stdc++.h>
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a[26]={},b[200000]={};
        vector<int> p;
        cin>>n>>m;
        string s;
        cin>>s;p.resize(m);b[n]++;
        for(int i=0;i<m;i++)
        {cin>>p[i];b[p[i]-1]++;}int sp=m+1;
        for(int i=0;i<n;i++)
        {
        	cout<<sp<<endl;
            if(sp>0)
            a[s[i]-97]+=sp;
            if(b[i]>0)
            sp-=b[i];
        }
        for(int i=0;i<26;i++)
        cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}