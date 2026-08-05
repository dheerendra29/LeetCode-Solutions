class Solution {
public:

    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL)
            return true;

        if (root == NULL || subRoot == NULL)
            return false;

        if (root->val != subRoot->val)
            return false;

        return sameTree(root->left, subRoot->left) &&
               sameTree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL)
            return false;

        if (sameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};