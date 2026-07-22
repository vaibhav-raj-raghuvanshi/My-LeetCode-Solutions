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
private:
    long long int sol,total;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        dfs(root->left);
        dfs(root->right);
        total += root->val;
    }
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        sol= max(sol,((l+r+root->val) * (total - (l+r+root->val))));
        return l+r+root->val;
    }
public:
    int maxProduct(TreeNode* root) {
        sol = 0;
        total = 0;
        dfs(root);
        solve(root);
        long long mod = 1e9+7;
        return sol%mod;
    }
};