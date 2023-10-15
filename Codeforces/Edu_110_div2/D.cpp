#include<bits/stdc++.h>
#define ll long long
#define xll __int128
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define Fo(i,q,n) for(int i=q;i<n;i++)
#define rFo(i,q,n) for(int i=n-1;i>=q;i--)
#define fO(i,n,k) for(int i=0;i<n;i+=k)
#define FO(i,q,n,k) for(int i=q;i<n;i+=k)
#define zero(a,n) memset(a,0,sizeof(a[0])*n)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
#define TIK auto start = chrono::high_resolution_clock::now();
#define TOK auto end = chrono::high_resolution_clock::now();double time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count();time_taken *= 1e-9;cerr << "Time taken:" << fixed << time_taken << setprecision(9);cerr << " sec" << endl;
using namespace std;
const int MOD=1000000007;
void print(){cout <<endl;}
template <typename T, typename... Types> 
void print(T var1, Types... var2){cout << var1 << " " ;print(var2...) ;}
//ceil of a/b
template <typename T>
T fceil(T a,T b){return (T)(a+b-1)/b;}
template <typename T>
void printvec(vector<T> v){ for(int i=0;i<(int)v.size();i++){ cout<<v[i]<<" ";} cout<<endl;}
template <typename T>
void printarr(T a[],int n){ for(int i=0;i<n;i++){ cout<<a[i]<<" ";} cout<<endl;}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//const int N=2e5;
//int arr[N+1];

struct Node{
    char choice;
    int val;
    Node *left;
    Node *right;
    Node *parent;
};
Node* createNode(char choice){
    Node *node = new Node;
    node->left=NULL;
    node->right=NULL;
    node->parent=NULL;
    node->choice = choice;
    node->val=-1;
    return node;
}
void calc(Node *root){
    if(root){
        if(!root->left){
            root->val = (root->choice=='?')?2:1;
            return;
        }
        calc(root->left);
        calc(root->right);
        if(root->choice=='?'){
            root->val = root->left->val + root->right->val;
        }
        else if(root->choice=='0'){
            root->val = root->left->val;
        }
        else if(root->choice=='1'){
            root->val = root->right->val;
        }
    }
}
void recalc(Node *node){
    if(node){
        if(!node->left){
            node->val = (node->choice=='?')?2:1;
        }
        else{
            if(node->choice=='?'){
                node->val = node->left->val + node->right->val;
            }
            else if(node->choice=='0'){
                node->val = node->left->val;
            }
            else if(node->choice == '1'){
                node->val = node->right->val;
            }
        }
        //update parent
        recalc(node->parent);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        int k;
        cin>>k;
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        //create tree
        vector<Node*> tree;
        tree.pb(createNode(s[0]));
        for(int i=0;2*i+2<(int)s.size();i++){
            tree.pb(createNode(s[2*i+1]));
            tree.pb(createNode(s[2*i+2]));
            tree[i]->left = tree[2*i+2];
            tree[i]->right = tree[2*i+1];
            tree[2*i+1]->parent = tree[i];
            tree[2*i+2]->parent = tree[i];
        }
        calc(tree[0]);
        //cout<<"#"<<tree[0]->val<<endl;
        int q;
        cin>>q;
        while(q--){
            int p;
            char c;
            cin>>p>>c;
            tree[(int)s.size()-p]->choice=c;
            recalc(tree[(int)s.size()-p]);
            cout<< tree[0]->val <<endl;
        }                     
    }
    return 0;
}






/*NOTE: Take MOD after sorting and not before sorting!\n: While casting to long long 1LL*a*b works while a*b*1LL doesn't*/
