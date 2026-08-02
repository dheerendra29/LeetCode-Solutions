class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    void fill(vector<vector<string>>& ans, TreeNode* root,
              int row, int left, int right) {

        if (root == NULL)
            return;

        int mid = left + (right - left) / 2;

        ans[row][mid] = to_string(root->val);

        fill(ans, root->left, row + 1, left, mid - 1);
        fill(ans, root->right, row + 1, mid + 1, right);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int rows = h;
        int cols = pow(2, h) - 1;

        vector<vector<string>> ans(rows, vector<string>(cols, ""));

        fill(ans, root, 0, 0, cols - 1);

        return ans;
    }
};