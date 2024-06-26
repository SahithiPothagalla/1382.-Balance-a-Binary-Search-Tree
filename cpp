/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*>inorder;
    void buildInorder(TreeNode* root){
        if(!root)return;
        buildInorder(root->left);
        inorder.push_back(root);
        buildInorder(root->right);
    }
    TreeNode* balanceUtil(TreeNode* root,int is,int ie){
        if(is>ie)return NULL;
        int mid=(is+ie)/2;
        root=inorder[mid];
        root->left=balanceUtil(root->left,is,mid-1);
        root->right=balanceUtil(root->right,mid+1,ie);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        buildInorder(root);
        return balanceUtil(root,0,inorder.size()-1);
    }
};
