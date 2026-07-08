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
    int ans=0;
    void dfs(TreeNode*node,int mask){
        mask^=(1LL<<(node->val));

        if(node->right==NULL && node->left==NULL){
            int c=0;
            for(int i=0;i<10;i++){
                if(((1LL<<i)&mask)!=0){
                    c++;
                }
            }
            ans+=(c<=1);
            return;
        }
        if(node->right){
            dfs(node->right,mask);
        }
        if(node->left){
            dfs(node->left,mask);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};