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

   bool equal(TreeNode* root, TreeNode* subRoot){

    if(root == nullptr && subRoot == nullptr) return true;

    if(root == nullptr || subRoot == nullptr) return false;
    
    if(root -> val != subRoot -> val) return false;

    return equal(root -> left, subRoot -> left) &&
           equal(root -> right, subRoot -> right);

   }
   
   bool fun(TreeNode* root, TreeNode* subRoot){

    if(root == nullptr) return false;

    if(root -> val == subRoot -> val){
        if(equal(root, subRoot)) return true;
    } 
        

   return fun(root -> left, subRoot) ||
    fun(root -> right, subRoot);
   }

   
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return fun(root, subRoot);
     }   
};