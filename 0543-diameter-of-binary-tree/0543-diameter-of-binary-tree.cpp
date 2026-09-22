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

    int res = 0;

    void fun(TreeNode* root, int& totalEdges){
        if(root == nullptr) return;

        int leftEdges = 0;
        int rightEdges = 0;

        fun(root -> left, leftEdges);
        fun(root -> right, rightEdges);

        if(root -> left != nullptr) leftEdges++;
        if(root -> right != nullptr) rightEdges++;
        
        int sum = leftEdges + rightEdges;

        res = max(res, sum);

        totalEdges = max(leftEdges, rightEdges);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int totalEdges = 0;
        fun(root, totalEdges);

        return res;
    }
};