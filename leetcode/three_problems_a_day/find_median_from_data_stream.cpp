#inlcude<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> m;
    multiset<int>::iterator l,h;
    MedianFinder() {
        l = m.begin();
        h = m.begin();
    }
    
    void addNum(int num) {
        int n=m.size();
        m.insert(num);
        if(n==0){
            l=m.begin();
            h=m.begin();
        }
        else if(n%2){
            //cout<< *l << *h<<endl;
            if(num<*l){
                l--;
            }
            else{
                h++;
            }
            //cout<< *l << *h<<endl;
        }
        else{
            if(num>= *l && num< *h ){
                l++;
                h--;
            }
            else if(num<*l){
                h=l;
            }
            else{
                l=h;
            }
        }
    }
    
    double findMedian() {
        if(m.size()&1){
            return *l;  
        }
        else{
             //cout<<*l<<"*"<<*h<<endl;
             return (double)(*l+*h)/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */