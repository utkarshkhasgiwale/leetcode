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

    int res = INT_MIN;

    void fun(TreeNode* root, int& totalPathSum){
        if(root == nullptr) return;

        int leftSum = 0;
        int rightSum = 0;

        fun(root -> left, leftSum);
        fun(root -> right, rightSum);

        leftSum = max(0, leftSum);
        rightSum = max(0, rightSum);

        int currSum = leftSum + root -> val + rightSum;

        res = max(res, currSum);

        totalPathSum = root -> val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {

        int totalPathSum = 0;
        fun(root, totalPathSum);
        return res;
    }
};