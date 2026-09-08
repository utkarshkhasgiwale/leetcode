class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> res;

        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int lvlSize = q.size();
            vector<int> tmp;

            while (lvlSize--) {

                TreeNode* t = q.front();
                q.pop();

                tmp.push_back(t->val);

                if (t->left != nullptr)
                    q.push(t->left);

                if (t->right != nullptr)
                    q.push(t->right);
            }

            res.push_back(tmp);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};