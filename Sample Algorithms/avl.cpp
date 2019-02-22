#include<bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct node{
  int data;
  struct node *left;
  struct node *right;
  int height;
}NODE;

int height(NODE *n){
  if(n){
    return n->height;
  }
  return 0;
}

NODE *createNode(int data){
  NODE *node=new NODE;
  node->data=data;
  node->left=NULL;
  node->right=NULL;
  node->height=1;
  return node;
}

NODE *rightRotate(NODE *y){
  NODE *x=y->left;
  NODE *t=x->right;

  x->right=y;
  y->left=t;

  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;
  return x;
}

NODE *leftRotate(NODE *x){
  NODE *y=x->right;
  NODE *t=x->left;

  y->left=x;
  x->right=t;

  x->height = max(height(x->left),height(x->right))+1;
  y->height = max(height(y->left),height(y->right))+1;
  return y;
}
int getBalance(NODE *N) {
    if(N){
      return height(N->left)-height(N->right);
    }
    return 0;
}

NODE *insert(NODE *node,int data){
  if(node){
    if(data<node->data){
      //insert on left
      node->left=insert(node->left,data);
    }
    else{
      //insert on right
      node->right=insert(node->right,data);
    }
    node->height=max(height(node->left),height(node->right))+1;
    //check balance factor
     int balance=getBalance(node);
     //left left
     if(balance>1 && data<node->left->data){
       return rightRotate(node);
     }
     //left right
     if(balance>1 && data>node->left->data){
       node->left=leftRotate(node->left);
       return rightRotate(node);
     }
     //rigth left
     if(balance<-1 && data<node->right->data){
       node->right=rightRotate(node->right);
       return leftRotate(node);
     }
     //right right
     if(balance<-1 && data>node->right->data){
       return rightRotate(node);
     }
     return node;
  }
  return createNode(data);
}

void inorder(NODE *root){
  if(root){
    inorder(root->left);
    cout<<root->data<<","<<root->height<<endl;
    inorder(root->right);
  }
}
int main(){
  int n,temp;
  cin>>n;
  NODE *root=NULL;
  for(int i=0;i<n;i++){
    cin>>temp;
    root=insert(root,temp);
  }
  inorder(root);
 return 0;
 }
