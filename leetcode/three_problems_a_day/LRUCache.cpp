/*Important use list and not deque as multiple inserts in front of 
deque pushes elements back messing the addresses stored in map
List on other hand creates new element
*/
class LRUCache {
public:
    list< pair<int,int> > dq;
    unordered_map<int,list<pair<int,int> >::iterator> cache;
    int capacity;
    LRUCache(int capacity) {
       this->capacity=capacity;
    }
    void display(int key){
        cout<<key<<" :"<<endl;
        //cout<<dq.front().<<" "<<dq.front().
        cout<< (*cache[key]).first << (*cache[key]).second <<endl;
    }
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            //display(key);
            int val = (*cache[key]).second;
            dq.erase(cache[key]);
            dq.push_front(make_pair(key,val));
            cache[key] = dq.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            dq.erase(cache[key]);
            cache.erase(key);
            dq.push_front(make_pair(key,value));
            cache[key] = dq.begin();  
        }
        else{
            //cout<<capacity<<endl;
            if(dq.size()<capacity){
                dq.push_front(make_pair(key,value));
                cache[key] = dq.begin();
            }
            else{
                //cout<<dq.end()<<endl;
                cache.erase(dq.back().first);
                dq.pop_back();
                dq.push_front(make_pair(key,value));
                cache[key]=dq.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */