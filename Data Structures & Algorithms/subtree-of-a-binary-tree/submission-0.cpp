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
    void solve(TreeNode* root, TreeNode* subRoot, vector<TreeNode*> &v){
       if(root == NULL) return;
        if(root -> val == subRoot -> val){
            v.push_back(root);
           //return;
        }       

        solve(root -> left, subRoot,v);
        solve(root -> right, subRoot,v);
    }

    bool check(TreeNode* root, TreeNode* subRoot){
        if(root != NULL and subRoot == NULL || root == NULL and subRoot != NULL ) return false;
        if(root == NULL and subRoot == NULL) return true;

        

        bool leftAns = check(root -> left, subRoot -> left);
        bool rightAns = check (root -> right, subRoot -> right);

        return leftAns and rightAns and (root -> val == subRoot -> val);


    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        vector<TreeNode*> v;
       solve(root,subRoot,v);

       for(int i = 0; i < v.size(); i++){
        cout << v[i] -> val << endl;
            if(check(v[i],subRoot) == true) return true;
       }

       return false;

        
    }
};
