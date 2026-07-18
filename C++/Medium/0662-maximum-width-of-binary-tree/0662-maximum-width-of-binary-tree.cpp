class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        long long sol = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            long long mn = q.front().second;
            long long first = 0, last = 0;
            for(int i = 0;i<n;i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                q.pop();
                idx -= mn;
                if(i == 0){
                    first = idx;
                }
                if(i == n-1){
                    last = idx;
                }
                if(node->left){
                    q.push({node->left,idx*2+1});
                }
                if(node->right){
                    q.push({node->right,idx*2+2});
                }
            }
            sol = max(sol,last-first+1);
        }
        return sol;
    }
};
