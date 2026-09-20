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

    vector<vector<int>> res;
    void fun(TreeNode* root, int targetSum, int sum, vector<int>& dairy){
        if(root == nullptr) return;

        sum += root -> val;
        dairy.push_back(root -> val);

        if(root -> left == nullptr && root -> right == nullptr){
            if(targetSum == sum){
                res.push_back(dairy);
                dairy.pop_back();
                return;
            }
        }

        fun(root -> left, targetSum, sum, dairy);
        fun(root -> right, targetSum, sum, dairy);

        dairy.pop_back();


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> dairy;
        fun(root, targetSum, 0, dairy);
        return res;
    }
};