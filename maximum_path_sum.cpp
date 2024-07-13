#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathDown(root, maxSum);
        return maxSum;
    }

private:
    int maxPathDown(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;

        int left = max(0, maxPathDown(node->left, maxSum));
        int right = max(0, maxPathDown(node->right, maxSum));

        maxSum = max(maxSum, left + right + node->val);

        return max(left, right) + node->val;
    }
};


TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createTree();

    int result = solution.maxPathSum(root);
    cout << "Maximum path sum: " << result << endl;

    return 0;
}
