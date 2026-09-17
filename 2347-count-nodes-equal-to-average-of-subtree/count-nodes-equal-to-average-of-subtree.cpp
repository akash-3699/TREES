class Solution {
public:
    pair<int,int> postorder(TreeNode* root, int &ans) {
        if (!root)
            return {0, 0};

        pair<int,int> left = postorder(root->left, ans);
        pair<int,int> right = postorder(root->right, ans);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        postorder(root, ans);
        return ans;
    }
};