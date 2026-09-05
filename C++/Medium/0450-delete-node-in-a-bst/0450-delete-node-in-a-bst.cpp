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
    int success(TreeNode* root){
        if(root->left == NULL){
            return root->val;
        }
        return success(root->left);
    }
    TreeNode* del(TreeNode* root, int key){
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            if(root->left == NULL){
                return root->right;
            }
            if(root->right == NULL){
                return root->left;
            }
            int val = success(root -> right);
            del(root, val);
            root->val = val;
        }else if(root -> val > key){
            root->left = del(root->left, key);
        }else{
            root -> right = del(root->right, key);
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return del(root, key);
    }
};