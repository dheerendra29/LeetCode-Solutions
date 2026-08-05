class Solution {
public:
    vector<int> ans;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);       // Left
        ans.push_back(root->val);  // Root
        inorder(root->right);      // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};