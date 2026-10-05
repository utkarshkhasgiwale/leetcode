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

    int idx = 0;

    TreeNode* fun(vector<int>& preorder, int low, int high){

        if(idx == preorder.size())
        return nullptr;


        if(preorder[idx] < low || preorder[idx] > high) return nullptr;
        
        TreeNode* node = new TreeNode(preorder[idx]);

        idx++;

        TreeNode* left = fun(preorder, low, node -> val);
        node -> left = left;

        TreeNode* right = fun(preorder, node -> val, high);
        node -> right = right;

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return fun(preorder, INT_MIN, INT_MAX);
    }
};