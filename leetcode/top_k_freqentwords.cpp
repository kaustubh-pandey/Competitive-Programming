//Using sorting: O(nlogn)
class Solution {
public:
    static bool cmp(pair<int,string> p1,pair<int,string>p2){
        if(p1.first>p2.first){
            return true;
        }
        else if(p1.first==p2.first){
            if(p1.second<p2.second){
                return true;
            }
            return false;
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(string s:words){
            m[s]++;
        }
        vector< pair<int,string> > res;
        for(auto x:m){
            res.push_back(make_pair(x.second,x.first));
        }
        sort(res.begin(),res.end(),cmp);
        vector<string> v;
        for(int i=0;i<k;i++){
            v.push_back(res[i].second);
        }
        return v;
    }
};

// Using priority _queue(heap)  : O(n)
// priority_queue can be initialized in O(n), however adding elements one by takes O(logn) for each
// thus for n it takes O(nlogn). Hence here since we already have all the elements directly initialize
class Compare{
    public:
    Compare(){
        
    }
    bool operator()(pair<int,string> p1,pair<int,string>p2){
        if(p1.first<p2.first){
            return true;
        }
        else if(p1.first==p2.first){
            if(p1.second>p2.second){
                return true;
            }
            return false;
        }
        return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(string s:words){
            m[s]++;
        }
        vector< pair<int,string> > res;
        for(auto x:m){
            res.push_back(make_pair(x.second,x.first));
        }
        priority_queue< pair<int,string>, vector<pair<int,string> >, Compare> pq(res.begin(),res.end());
        //sort(res.begin(),res.end(),cmp);
        vector<string> v;
        for(int i=0;i<k;i++){
            auto tmp = pq.top();
            pq.pop();
            v.push_back(tmp.second);
        }
        return v;
    }
};