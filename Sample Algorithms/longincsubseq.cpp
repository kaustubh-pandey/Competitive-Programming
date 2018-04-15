#include <bits/stdc++.h>
 using namespace std;

// Binary search (note boundaries in the caller)
int CeilIndex(vector<pair<pair<double,double>,int> > &v, int l, int r, pair<pair<double,double>,int>  key) {
    while (r-l > 1) {
    int m = (l+r)/2;

    if (v[m].first.first >= key.first.first && v[m].first.second>=key.first.second)
        r = m;
    else
        l = m;
    }
 
    return r;
}
 
int LongestIncreasingSubsequenceLength(vector<pair<pair<double,double>,int> > &v,vector<pair<pair<double,double>,int> > &tail) {
    
    if (v.size() == 0){
        return 0;
    }
 
    
    int length = 1; // always points empty slot in tail
    
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i].first.first < tail[0].first.first && v[i].first.second < tail[0].first.second){
            // new smallest value
            tail[0] = v[i];
            
        }
        
        else if (v[i].first.first > tail[length-1].first.first && v[i].first.second > tail[length-1].first.second){
            // v[i] extends largest subsequence
            cout<<length<<"*"<<endl;
            tail[length++] = v[i];
        }
        else{
            // v[i] will become end candidate of an existing subsequence or
            // Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
            // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
        }
        int j=0;
    while(j<v.size()){
        cout<<tail[j].first.first<<","<<tail[j].first.second<<","<<tail[j].second <<" ";
        j++;
    }
    cout<<endl;
        
    }
    
    
    return length;
}
int main(){
    vector<pair<pair<double,double>,int> > v;
    
    int n;
    double c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c>>d;
        v.push_back(make_pair(make_pair(c,d),i+1));
    }
    vector<pair<pair<double,double>,int> > tail(v.size(), make_pair(make_pair(-1,-1),-1));
    cout<<LongestIncreasingSubsequenceLength(v,tail)<<endl;
    int i=0;
    while(i<n){
        cout<<tail[i].second <<" ";
        i++;
    }
    cout<<endl;
    return 0;
    
}