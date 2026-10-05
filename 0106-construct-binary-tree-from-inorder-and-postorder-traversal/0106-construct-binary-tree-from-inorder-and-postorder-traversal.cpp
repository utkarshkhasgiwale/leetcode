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
    unordered_map<int, int> f;

    TreeNode* fun(vector<int>& postorder, int low, int high, int& idx){

        if(low > high) return nullptr;

        TreeNode* node = new TreeNode(postorder[idx]);

        idx--;

        int id = f[node -> val];

        TreeNode* right = fun(postorder, id + 1, high, idx);
        node -> right = right;

        TreeNode* left = fun(postorder, low, id - 1, idx);
        node -> left = left;

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            f[inorder[i]] = i;
        }

        int idx = inorder.size() - 1;
        
        return fun(postorder, 0, inorder.size() - 1, idx);
    }
};