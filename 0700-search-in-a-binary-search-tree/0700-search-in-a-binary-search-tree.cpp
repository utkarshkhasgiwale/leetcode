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

    TreeNode* fun(TreeNode* root, int val, TreeNode* res){
        if(root == nullptr) return res;

        if(root -> val == val) {
            res = root;
            return res;
        }

        if(root -> val > val){
            return fun(root -> left, val, res);
        }
        else{
            return fun(root -> right, val, res);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = nullptr;
        return fun(root, val, res);
    }
};