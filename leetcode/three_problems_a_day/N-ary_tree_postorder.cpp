#include<bits/stdc++.h>
using namespace std;
//recursive solution
/*
void postOrd(Node *root, vector<int> &res){
        if(root){
             for(auto i = root->children.begin();i!=root->children.end();i++){
                postOrd(*i,res);
                res.push_back((*i)->val);
            }
            //res.push_back(root->val);   
        }
        return;
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        postOrd(root,res);
        if(root)
            res.push_back(root->val);
        return res;
    }
*/
//iterative
vector<int> postorder(Node* root) {
        vector<int> res;
        if(root){
            stack<Node*> st;
            st.push(root);
            //res.push_back(root->val);
            while(!st.empty()){
                Node* tmp = st.top();
                st.pop();
                res.push_back(tmp->val);
                for(auto i = tmp->children.begin();i!=tmp->children.end();i++){
                    st.push(*i);
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
}