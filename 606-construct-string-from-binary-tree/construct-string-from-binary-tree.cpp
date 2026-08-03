class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root == NULL)
            return "";

        string ans = to_string(root->val);

        // Left child exists
        if (root->left) {
            ans += "(" + tree2str(root->left) + ")";
        }
        // Left child doesn't exist but right child exists
        else if (root->right) {
            ans += "()";
        }

        // Right child exists
        if (root->right) {
            ans += "(" + tree2str(root->right) + ")";
        }

        return ans;
    }
};