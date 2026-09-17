/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    stack<TreeNode*> asce;
    stack<TreeNode*> dsce;

    // Returns next smallest node
    TreeNode* getSmall() {
        if (asce.empty())
            return nullptr;

        TreeNode* small = asce.top();
        asce.pop();

        TreeNode* rightChild = small->right;

        while (rightChild) {
            asce.push(rightChild);
            rightChild = rightChild->left;
        }

        return small;
    }

    // Returns next largest node
    TreeNode* getBig() {
        if (dsce.empty())
            return nullptr;

        TreeNode* big = dsce.top();
        dsce.pop();

        TreeNode* leftChild = big->left;

        while (leftChild) {
            dsce.push(leftChild);
            leftChild = leftChild->right;
        }

        return big;
    }

    bool fun(TreeNode* root, int k) {
        if (root == nullptr)
            return false;

        // Initialize ascending iterator
        TreeNode* t = root;

        while (t) {
            asce.push(t);
            t = t->left;
        }

        // Initialize descending iterator
        t = root;

        while (t) {
            dsce.push(t);
            t = t->right;
        }

        // Start from smallest and largest
        TreeNode* i = getSmall();
        TreeNode* j = getBig();

        while (i && j && i != j && i->val < j->val) {

            int sum = i->val + j->val;

            if (sum == k)
                return true;

            else if (sum > k)
                j = getBig();

            else
                i = getSmall();
        }

        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        return fun(root, k);
    }
};