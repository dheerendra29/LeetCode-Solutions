class Solution {
public:
    int ans = INT_MAX;
    int prev = -1;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != -1)
            ans = min(ans, root->val - prev);

        prev = root->val;

        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};