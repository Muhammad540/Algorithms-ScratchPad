// ps: give a binary tree, check if we can reach a leaf node from the root without passing through a node with value 0
// kinda like maze solving 

#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
    ~TreeNode(){
        delete left;
        delete right;
    }
};

bool canReachLeaf(TreeNode* root){
    if(!root || root->val==0){
        return false;
    }
    // check if reached root node 
    if (!root->left & !root->right){
        return true;
    }
    // check the left subtree
    if (canReachLeaf(root->left)){
        return true;
    }
    // check the right subtree
    if (canReachLeaf(root->right)){
        return true;
    }
    // if cant reach leaf from right or left sub tree just return false
    return false;
}

int main() {
    // Test Case 1: Simple path exists
    //      1
    //     / \
    //    2   3
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    std::cout << "Test Case 1 (Path exists): " << (canReachLeaf(root1) ? "Reachable" : "Not Reachable") << std::endl; // Expected: Reachable
    delete root1;

    // Test Case 2: Path blocked by 0
    //      1
    //     / \
    //    0   3
    //   /
    //  4
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->left->left = new TreeNode(4); // Leaf behind a 0
    root2->right = new TreeNode(3);      // Leaf reachable
    std::cout << "Test Case 2 (Path partially blocked): " << (canReachLeaf(root2) ? "Reachable" : "Not Reachable") << std::endl; // Expected: Reachable (via node 3)
    delete root2;

    // Test Case 3: All paths blocked by 0
    //      1
    //     / \
    //    0   0
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(0);
    root3->right = new TreeNode(0);
    std::cout << "Test Case 3 (All paths blocked): " << (canReachLeaf(root3) ? "Reachable" : "Not Reachable") << std::endl; // Expected: Not Reachable
    delete root3;

    // Test Case 4: Root is 0
    //      0
    //     / \
    //    1   2
    TreeNode* root4 = new TreeNode(0);
    root4->left = new TreeNode(1);
    root4->right = new TreeNode(2);
    std::cout << "Test Case 4 (Root is 0): " << (canReachLeaf(root4) ? "Reachable" : "Not Reachable") << std::endl; // Expected: Not Reachable
    delete root4;

    // Test Case 5: Root is the only node (and not 0)
    //      1
    TreeNode* root5 = new TreeNode(1);
    std::cout << "Test Case 5 (Root is leaf): " << (canReachLeaf(root5) ? "Reachable" : "Not Reachable") << std::endl; // Expected: Reachable
    delete root5;

    // Test Case 6: Empty tree
    TreeNode* root6 = nullptr;
    std::cout << "Test Case 6 (Empty tree): " << (canReachLeaf(root6) ? "Reachable" : "Not Reachable") << std::endl; // Expected: Not Reachable

     // Test Case 7: Deeper path
    //      1
    //     /
    //    2
    //   / \
    //  4   0
    // /     \
    //5       6 <-- unreachable leaf
    TreeNode* root7 = new TreeNode(1);
    root7->left = new TreeNode(2);
    root7->left->left = new TreeNode(4);
    root7->left->right = new TreeNode(0);
    root7->left->left->left = new TreeNode(5); // Reachable leaf
    root7->left->right->right = new TreeNode(6); // Unreachable leaf
    std::cout << "Test Case 7 (Deeper path): " << (canReachLeaf(root7) ? "Reachable" : "Not Reachable") << std::endl; // Expected: Reachable
    delete root7;

    return 0;
}  