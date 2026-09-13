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
public:

    int fun(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res){

        if(root == nullptr) return 0;

        int left = fun(root -> left, p, q, res);
        int right = fun(root -> right, p, q, res);

        int self = 0;

        if(root == p || root == q) self = 1;

        int total = left + right + self;

        if(total == 2 && res == nullptr) res = root;

        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q ) {
        TreeNode* res = nullptr;
         fun(root, p, q, res);
         return res;
    }
};