/* Definition of Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    void solve(Node* root, vector<int>& ans) {
        if (!root)
            return;

        // Left child exists but right child doesn't
        if (root->left && !root->right) {
            ans.push_back(root->left->data);
        }

        // Right child exists but left child doesn't
        if (!root->left && root->right) {
            ans.push_back(root->right->data);
        }

        solve(root->left, ans);
        solve(root->right, ans);
    }

    vector<int> noSibling(Node* root) {
        vector<int> ans;

        solve(root, ans);

        if (ans.empty())
            return {-1};

        sort(ans.begin(), ans.end());

        return ans;
    }
};