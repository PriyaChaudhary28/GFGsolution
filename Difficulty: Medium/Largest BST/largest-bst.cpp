/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeValue {
public:
    int minnode, maxnode, maxsize;

    NodeValue(int minnode, int maxnode, int maxsize)
        : minnode(minnode), maxnode(maxnode), maxsize(maxsize) {}
};

class Solution {
private:
    NodeValue helper(Node* root) {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = helper(root->left);
        auto right = helper(root->right);

        // If current node is greater than max in left and smaller than min in right,
        // it's a BST rooted at current node
        if (left.maxnode < root->data && root->data < right.minnode) {
            return NodeValue(
                min(root->data, left.minnode),
                max(root->data, right.maxnode),
                left.maxsize + right.maxsize + 1
            );
        }

        // If not BST, return maxsize of BST from children, but force current subtree to be invalid
        return NodeValue(INT_MIN, INT_MAX, max(left.maxsize, right.maxsize));
    }

public:
    int largestBst(Node* root) {
        return helper(root).maxsize;
    }
};
