/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool pathsum(TreeNode* root,int sum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            if(sum==root->val){
                return true;
            }
            return false;
        }
        bool left = pathsum(root->left,sum-(root->val));
        bool right= pathsum(root->right,sum-(root->val));
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return pathsum(root,sum);
    }
};