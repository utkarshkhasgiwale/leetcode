class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;
        bool leftToRight = 1;

        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int lvlSize = q.size();
            vector<int> tmp(lvlSize);

            int first = 0;
            int last = lvlSize - 1;

            while (lvlSize--) {

                TreeNode* t = q.front();
                q.pop();

                if (leftToRight == 1) {
                    tmp[first] = t->val;
                    first++;
                }
                else {
                    tmp[last] = t->val;
                    last--;
                }

                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
            }

            res.push_back(tmp);
            leftToRight = 1 - leftToRight;
        }

        return res;
    }
};