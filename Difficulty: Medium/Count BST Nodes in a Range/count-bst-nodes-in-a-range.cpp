/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    int getCount(Node* root, int l, int h) {
        if (!root)
            return 0;

        // Root value is smaller than range
        if (root->data < l) {
            return getCount(root->right, l, h);
        }

        // Root value is greater than range
        if (root->data > h) {
            return getCount(root->left, l, h);
        }

        // Root lies in range
        return 1 + getCount(root->left, l, h)
                 + getCount(root->right, l, h);
    }
};