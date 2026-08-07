class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        // Only right child exists
        if (root->left == NULL)
            return 1 + minDepth(root->right);

        // Only left child exists
        if (root->right == NULL)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left),
                       minDepth(root->right));
    }
};