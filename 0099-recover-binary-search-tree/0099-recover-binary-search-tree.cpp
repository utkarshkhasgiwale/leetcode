class Solution {
public:

    TreeNode* prev = nullptr;

    TreeNode* galat1 = nullptr;
    TreeNode* galat2 = nullptr;

    void fun(TreeNode* root) {

        if (root == nullptr)
            return;

        fun(root->left);

        if (prev != nullptr && root->val < prev->val) {

            if (galat1 == nullptr) {
                galat1 = prev;
            }

            galat2 = root;
        }

        prev = root;

        fun(root->right);
    }

    void recoverTree(TreeNode* root) {

        fun(root);

        swap(galat1->val, galat2->val);
    }
};