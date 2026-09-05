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
// private:
//     void solve(TreeNode* root, vector<int> &ans, int level){
//         if(root == NULL) return;

//         if(level == ans.size()){
//             ans.push_back(root -> val);
//         }

//         solve(root -> right,ans,level+1);
//         solve(root -> left, ans,level+1);
//     }
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        //solve(root,ans,0);
        if(root == NULL) return ans;

        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();

                if(level == ans.size()){
                    ans.push_back(node -> val);
                }

                if(node -> right) q.push({node -> right, level+1});
                if(node -> left) q.push({node -> left,level+1});
            }
        }

        return ans;
        
    }
};
