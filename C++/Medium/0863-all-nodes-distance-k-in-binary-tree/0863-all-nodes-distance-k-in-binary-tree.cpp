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
private:
    void findParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent, int key) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            parent[root->left] = root;
            findParents(root->left, parent, key);
        }
        if (root->right != NULL) {
            parent[root->right] = root;
            findParents(root->right, parent, key);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> vis;
        vector<int> sol;
        findParents(root, parent, target->val);
        queue<pair<int, TreeNode*>> q;
        vis[target] = true;
        q.push({k, target});
        while (!q.empty()) {
            int lev = q.front().first;
            TreeNode* temp = q.front().second;
            q.pop();
            if (lev == 0) {
                sol.push_back(temp->val);
                continue;
            }
            if (parent[temp] && !vis[parent[temp]]) {
                q.push({lev - 1, parent[temp]});
                vis[parent[temp]] = true;
            }
            if (temp->left && !vis[temp->left]) {
                q.push({lev - 1, temp->left});
                vis[temp->left] = true;
            }
            if (temp->right && !vis[temp->right]) {
                q.push({lev - 1, temp->right});
                vis[temp->right] = true;
            }
        }
        return sol;
    }
};
