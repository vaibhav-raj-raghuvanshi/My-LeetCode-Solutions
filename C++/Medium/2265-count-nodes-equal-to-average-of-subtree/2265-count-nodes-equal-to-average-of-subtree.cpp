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
    int sol;
    pair<int, int> backtrack(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
        pair<int ,int> p1 = backtrack(root->left);
        pair<int ,int> p2 = backtrack(root->right);
        if(floor((0.0 + p1.first + p2.first + root -> val)/(p1.second + p2.second + 1)) == root->val){
            sol++;
        }
        return {p1.first+p2.first+root->val, p1.second + p2.second + 1};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        backtrack(root);
        return sol;
    }
};