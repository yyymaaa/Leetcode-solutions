#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
int calculate(TreeNode* node, int currentSum) {
    if (node == nullptr) return 0;
    int newSum = (currentSum * 2) + node->val;
    if (node->left == nullptr && node->right == nullptr) return newSum;
    return calculate(node->left, newSum) + calculate(node->right, newSum);
}


int sumRootToLeaf(TreeNode* root) {
    return calculate(root, 0);
    }


int main() {    
    TreeNode* leftChild = new TreeNode(0);
    TreeNode* rightChild = new TreeNode(1);
    TreeNode* root = new TreeNode(1, leftChild, rightChild);

    int result = sumRootToLeaf(root);
    
    std::cout << "The total sum is: " << result << std::endl;
    std::cout << "Expected: 5 (binary 10 + 11)" << std::endl;

    // Cleanup memory, a good habit
    delete leftChild;
    delete rightChild;
    delete root;

    return 0;
}