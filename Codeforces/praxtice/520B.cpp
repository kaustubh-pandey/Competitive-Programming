#include<bits/stdc++.h>
using namespace std;
typedef struct NODE{
	int data;
	NODE *left;
	NODE *right;
}NODE;
 
NODE *createNode(int data){
	NODE *node =  new NODE;
	node->data=data;
	node->right=NULL;
	node->left=NULL;
	return node;
}
NODE* bfs(int n,int m){
	NODE *root=createNode(n);
	queue<NODE*> q;
	q.push(root);
	int a[2*10000+1];
	memset(a,0,sizeof(a));
	a[n]=1;
	while(!q.empty()){
		NODE* curr = q.front();
		//cout<<curr->data<<endl;
		q.pop();
		if(curr->data==m){
			break;
		}
		if(curr->data - 1 >0 && a[curr->data - 1]==0){
			NODE *left = createNode(curr->data - 1);
			curr->left=left;
			if(left->data==m){
				break;
			}
			q.push(left);
			a[curr->data - 1]=1;
		}
		
		if(curr->data <= m && curr->data *2>0 && a[curr->data *2]==0){
			NODE *right = createNode(curr->data * 2);
			curr->right=right;
			if(right->data==m){
				break;
			}
			q.push(right);
			a[curr->data *2]=1;
		}		
	}
	return root;
}
void bfs_(NODE *root){
	queue<NODE*> q;
	q.push(root);
	while(!q.empty()){
		NODE* curr = q.front();
		cout<<curr->data<<endl;
		q.pop();
		if(curr->left!=NULL){
			q.push(curr->left);
		}
		if(curr->right!=NULL){
			q.push(curr->right);
		}
	}
}
int dfs(NODE *root,int m){
	if(root==NULL){
		return INT_MIN;
	}
	//cout<<root->data<<endl;
	if(root->data==m){
		return 0;
	}
	return max(1+dfs(root->left,m),1+dfs(root->right,m));
}
int main(){
	int n,m;
	cin>>n>>m;
	NODE *root = bfs(n,m);
	//bfs_(root);
	cout<<dfs(root,m)<<endl;
	return 0;
}